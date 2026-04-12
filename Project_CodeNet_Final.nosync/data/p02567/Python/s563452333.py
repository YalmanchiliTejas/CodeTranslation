import sys
import numpy as np
import numba
from numba import njit, b1, i4, i8, f8

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

@njit((numba.types.optional(i8), ) * 2, cache=True)
def seg_f(x, y):
    if x is None:
        return y
    if y is None:
        return x
    return max(x, y)


@njit((i8[:], ), cache=True)
def build(raw_data):
    N = len(raw_data)
    seg = np.empty(N + N, np.int64)
    seg[N:] = raw_data
    for i in range(N - 1, 0, -1):
        seg[i] = seg_f(seg[i << 1], seg[i << 1 | 1])
    return seg


@njit((i8[:], i8, i8), cache=True)
def set_val(seg, i, x):
    N = len(seg) // 2
    i += N
    seg[i] = x
    while i > 1:
        i >>= 1
        seg[i] = seg_f(seg[i << 1], seg[i << 1 | 1])


@njit((i8[:], i8, i8), cache=True)
def fold(seg, l, r):
    vl = vr = None
    N = len(seg) // 2
    l, r = l + N, r + N
    while l < r:
        if l & 1:
            vl = seg_f(vl, seg[l])
            l += 1
        if r & 1:
            r -= 1
            vr = seg_f(seg[r], vr)
        l, r = l >> 1, r >> 1
    return seg_f(vl, vr)


@njit((i8[:], i8, i8), cache=True)
def max_right(seg, l, x):
    """[l,r) が ok であるような最大の r を返す"""
    N = len(seg) // 2

    def is_ok(v):
        return v < x

    v = None
    i, node_l, node_w = l + N, l, 1
    while True:
        if not (i & 1):
            i >>= 1
            node_w <<= 1
            continue
        if node_l + node_w > N:
            break
        v1 = seg_f(v, seg[i])
        if is_ok(v1):
            v, i = v1, (i + 1) >> 1
            node_l, node_w = node_l + node_w, node_w << 1
        else:
            break
    # 奇数セルに居て、とりきれないことが分かっている。偶数をとっていく
    i, node_w = i << 1, node_w >> 1
    while node_w:
        if node_l + node_w > N:
            i, node_w = i << 1, node_w >> 1
            continue
        v1 = seg_f(v, seg[i])
        if is_ok(v1):
            v, i = v1, (i + 1) << 1
            node_l, node_w = node_l + node_w, node_w >> 1
        else:
            i, node_w = i << 1, node_w >> 1
    i >>= 1
    return i - N

@njit((i8, i8[:], i8[:]), cache=True)
def main(N, A, query):
    seg = build(A)
    for i in range(0, len(query), 3):
        t, a, b = query[i:i + 3]
        if t == 1:
            set_val(seg, a - 1, b)
        elif t == 2:
            print(fold(seg, a - 1, b))
        elif t == 3:
            print(max_right(seg, a - 1, b) + 1)

N, Q = map(int, readline().split())
A = np.array(readline().split(), np.int64)
query = np.array(read().split(), np.int64)

main(N, A, query)