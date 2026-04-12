import sys
import numpy as np
import numba
from numba import njit
i8 = numba.int64

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

A = np.array([1, 2, 3])

@njit((numba.types.optional(i8), ) * 2, cache=True)
def seg_f(x, y):
    if x is None:
        return y
    if y is None:
        return x
    return max(x, y)


@njit((i8, i8), cache=True)
def lazy_f(a, b):
    return a + b


@njit((i8, i8), cache=True)
def operate_f(x, a):
    return x + a


@njit((i8[:], i8[:], i8), cache=True)
def _eval_at(seg, lazy, i):
    return operate_f(seg[i], lazy[i])


@njit((i8[:], i8[:], i8), cache=True)
def _propagate_at(seg, lazy, i):
    seg[i] = _eval_at(seg, lazy, i)
    lazy[i << 1] = lazy_f(lazy[i << 1], lazy[i])
    lazy[i << 1 | 1] = lazy_f(lazy[i << 1 | 1], lazy[i])
    lazy[i] = 0


@njit((i8[:], ), cache=True)
def build(raw_data):
    N = len(raw_data)
    seg = np.empty(N + N, np.int64)
    seg[N:] = raw_data
    for i in range(N - 1, 0, -1):
        seg[i] = seg_f(seg[i << 1], seg[i << 1 | 1])
    return seg


@njit((i8[:], i8[:], i8), cache=True)
def _propagate_above(seg, lazy, i):
    H = 0
    while 1 << H <= i:
        H += 1
    for h in range(H - 1, 0, -1):
        _propagate_at(seg, lazy, i >> h)


@njit((i8[:], i8[:], i8), cache=True)
def _recalc_above(seg, lazy, i):
    while i > 1:
        i >>= 1
        seg[i] = seg_f(_eval_at(seg, lazy, i << 1),
                       _eval_at(seg, lazy, i << 1 | 1))


@njit((i8[:], i8[:], i8, i8), cache=True)
def set_val(seg, lazy, i, x):
    N = len(seg) // 2
    i += N
    _propagate_above(seg, lazy, i)
    seg[i], lazy[i] = x, 0
    _recalc_above(seg, lazy, i)


@njit((i8[:], i8[:], i8, i8), cache=True)
def fold(seg, lazy, l, r):
    N = len(seg) // 2
    l, r = l + N, r + N
    _propagate_above(seg, lazy, l // (l & -l))
    _propagate_above(seg, lazy, r // (r & -r) - 1)
    vl = vr = None
    while l < r:
        if l & 1:
            vl = seg_f(vl, _eval_at(seg, lazy, l))
            l += 1
        if r & 1:
            r -= 1
            vr = seg_f(_eval_at(seg, lazy, r), vr)
        l, r = l >> 1, r >> 1
    return seg_f(vl, vr)


@njit((i8[:], i8[:], i8, i8, i8), cache=True)
def operate_range(seg, lazy, l, r, x):
    N = len(seg) // 2
    l, r = l + N, r + N
    l0, r0 = l // (l & -l), r // (r & -r) - 1
    _propagate_above(seg, lazy, l0)
    _propagate_above(seg, lazy, r0)
    while l < r:
        if l & 1:
            lazy[l] = lazy_f(lazy[l], x)
            l += 1
        if r & 1:
            r -= 1
            lazy[r] = lazy_f(lazy[r], x)
        l, r = l >> 1, r >> 1
    _recalc_above(seg, lazy, l0)
    _recalc_above(seg, lazy, r0)

@njit((i8, i8[:]), cache=True)
def main(N, LRA):
    L, R, A = LRA[::3], LRA[1::3], LRA[2::3]
    ind = R.argsort()
    L, R, A = L[ind], R[ind], A[ind]
    seg = np.zeros((2 * N + 2), np.int64)
    lazy = np.zeros_like(seg)
    for r in range(1, N + 1):
        a, b = np.searchsorted(R, [r, r + 1])
        set_val(seg, lazy, r, seg[1])
        for i in range(a, b):
            operate_range(seg, lazy, L[i], r + 1, A[i])
    return seg[1]

N, M = map(int, readline().split())
LRA = np.array(read().split(), np.int64)

print(main(N, LRA))