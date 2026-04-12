code = r"""
# distutils: language=c++
# distutils: include_dirs=[/home/contestant/.local/lib/python3.8/site-packages/numpy/core/include, /opt/atcoder-stl]
# cython: language_level=3
# cython: boundscheck=False
# cython: wraparound=False
from libcpp cimport bool
from libcpp.vector cimport vector
cdef extern from "<atcoder/segtree>" namespace "atcoder":
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
    ctypedef int op "myop"
    ctypedef int e "mye"
    ctypedef int f "myf"
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
from libc.stdio cimport scanf, printf
cdef main():
    cdef int n, q, i, t, u
    scanf('%d%d', &n, &q)
    cdef vector[seg_t] a = vector[seg_t](n)
    for i in range(n): scanf('%ld', &a[i])
    cdef segtree[seg_t, op, e] *seg = new segtree[seg_t, op, e](a)
    for i in range(q):
        scanf('%d%d%d', &t, &u, &v)
        if t == 1:
            seg.set(u - 1, v)
        elif t == 2:
            printf('%ld\n', seg.prod(u - 1, v))
        else:
            printf('%ld\n', seg.max_right[f](u - 1) + 1)
main()
"""
import os, sys
if sys.argv[-1] == 'ONLINE_JUDGE':
    open('solve.pyx', 'w').write(code)
    os.system('cythonize -i -3 -b solve.pyx')
import solve