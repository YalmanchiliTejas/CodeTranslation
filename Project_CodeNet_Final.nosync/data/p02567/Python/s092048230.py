code = r"""
# distutils: language=c++
# distutils: include_dirs=/opt/atcoder-stl
from libcpp cimport bool
from libcpp.vector cimport vector
cdef extern from "<atcoder/segtree>" namespace "atcoder" nogil:
    cdef cppclass segtree[S, OP, E]:
        segtree(vector[S] v)
        void set(int p, S x)
        S get(int p)
        S prod(int l, int r)
        S all_prod()
        int max_right[F](int l)
        int min_left[F](int r)
ctypedef long seg_t
cdef extern from *:
    ctypedef int op_t "myop"
    ctypedef int e_t "mye"
    ctypedef int f_t "myf"
    cdef seg_t myop(seg_t a, seg_t b) nogil
    cdef seg_t mye() nogil
    cdef bool myf(seg_t k) nogil
cdef seg_t myop(seg_t a, seg_t b) nogil:
    if a > b:
        return a
    else:
        return b
cdef seg_t mye() nogil:
    return -1000000000
cdef seg_t v
cdef bool myf(seg_t k) nogil:
    return k < v

from cython.parallel cimport prange
from libc.stdio cimport scanf, printf
cdef void main():
    cdef int n, q, i, t, u
    scanf('%d%d', &n, &q)
    cdef vector[seg_t] a = vector[seg_t](n)
    for i in prange(n, nogil=1): scanf('%ld', &a[i])
    cdef segtree[seg_t, op_t, e_t] *seg = new segtree[seg_t, op_t, e_t](a)
    for i in prange(q, nogil=1):
        scanf('%d%d%d', &t, &u, &v)
        if t == 1:
            seg.set(u - 1, v)
        elif t == 2:
            printf('%ld\n', seg.prod(u - 1, v))
        else:
            printf('%ld\n', seg.max_right[f_t](u - 1) + 1)
main()
"""
import os, sys
if sys.argv[-1] == 'ONLINE_JUDGE':
    open('solve.pyx', 'w').write(code)
    os.system('cythonize -i -3 -b solve.pyx')
import solve