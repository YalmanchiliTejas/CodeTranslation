code = """

# distutils: language=c++
# distutils: include_dirs=[/home/USERNAME/.local/lib/python3.8/site-packages/numpy/core/include, /opt/atcoder-stl]
# cython: boundscheck=False
# cython: wraparound=False

from libcpp.utility cimport pair
from libcpp.string cimport string
from libcpp.vector cimport vector
from cython.operator cimport dereference
from libcpp cimport bool
from cython.operator cimport preincrement
from libc.stdio cimport getchar, printf
from cython.operator cimport predecrement
cpdef inline vector[int] ReadInt(int n):
    cdef int b, c
    cdef vector[int] *v = new vector[int]()
    for i in range(n):
        c = 0
        while 1:
            b = getchar() - 48
            if b < 0: break
            c = c * 10 + b
        v.push_back(c)
    return v[0]

cpdef inline vector[string] Read(int n):
    cdef char c
    cdef vector[string] *vs = new vector[string]()
    cdef string *s
    for i in range(n):
        s = new string()
        while 1:
            c = getchar()
            if c<=32: break
            s.push_back(c)
        vs.push_back(s[0])
    return vs[0]

cpdef inline void PrintLongN(vector[long] l):
    cdef int n = l.size()
    for i in range(n): printf("%ld\\n", l[i])

cpdef inline void PrintLong(vector[long] l):
    cdef int n = l.size()
    for i in range(n): printf("%ld ", l[i])
cdef extern from "<set>" namespace "std" nogil:
    cdef cppclass multiset[T]:
        ctypedef T value_type
        cppclass iterator:
            T& operator*()
            iterator operator++()
            iterator operator--()
            bint operator==(iterator)
            bint operator!=(iterator)
        cppclass reverse_iterator:
            T& operator*()
            iterator operator++()
            iterator operator--()
            bint operator==(reverse_iterator)
            bint operator!=(reverse_iterator)
        cppclass const_iterator(iterator):
            pass
        cppclass const_reverse_iterator(reverse_iterator):
            pass
        multiset() except +
        multiset(multiset&) except +
        iterator begin()
        reverse_iterator rbegin()
        size_t count(const T&)
        bint empty()
        iterator end()
        reverse_iterator rend()
        iterator find(T&)
        size_t size()
        iterator upper_bound(const T&)
        iterator lower_bound(T&)
        pair[iterator, bint] insert(const T&) except +
        iterator erase(iterator)

cdef extern from *:
    ctypedef long long ll "long long"


cdef class MultiSet:
    cdef multiset[ll] *_thisptr
    def __cinit__(self):
        self._thisptr = new multiset[ll]()
    cpdef int size(self):
        return self._thisptr.size()
    cpdef bool empty(self):
        return self._thisptr.empty()
    cpdef void add(self, ll x):
        self._thisptr.insert(x)
    cpdef void remove(self, ll x):
        self._thisptr.erase(self._thisptr.find(x))
    cpdef int count(self, ll x):
        return self._thisptr.count(x)
    cpdef ll min(self):
        return dereference(self._thisptr.begin())
    cpdef ll max(self):
        return dereference(self._thisptr.rbegin())
    def lower_bound(self, x):
        cdef multiset[ll].iterator itr = self._thisptr.lower_bound(x)
        if itr == self._thisptr.end():
            return None
        else:
            return dereference(itr)
    def upper_bound(self, ll x):
        cdef multiset[ll].iterator itr = self._thisptr.upper_bound(x)
        if itr == self._thisptr.end():
            return None
        else:
            return dereference(itr)
    def next(self, x):
        if x >= self.max():
            return None
        cdef multiset[ll].iterator itr = self._thisptr.find(x)
        cdef int c = self._thisptr.count(x)
        for i in range(c):
            preincrement(itr)
        return dereference(itr)
    cpdef prev(self, x):
        if x <= self.min():
            return None
        cdef multiset[ll].iterator itr = self._thisptr.find(x)
        predecrement(itr)
        return dereference(itr)
    cpdef ll pop_min(self):
        cdef multiset[ll].iterator itr = self._thisptr.begin()
        cdef ll ret = dereference(itr)
        self._thisptr.erase(itr)
        return ret
    cpdef ll pop_max(self):
        cdef multiset[ll].reverse_iterator itr = self._thisptr.rbegin()
        cdef ll ret = dereference(itr)
        self._thisptr.erase(self._thisptr.find(ret))
        return ret
    def __contains__(self, x):
        if self._thisptr.find(x)==self._thisptr.end():
            return False
        else:
            return True
"""


import os, sys, getpass

if sys.argv[-1] == 'ONLINE_JUDGE':
    code = code.replace("USERNAME", getpass.getuser())
    open('atcoder.pyx','w').write(code)
    os.system('cythonize -i -3 -b atcoder.pyx')
    sys.exit(0)


from atcoder import MultiSet, ReadInt

def main():
    ms = MultiSet()
    N = ReadInt(1)[0]
    for i in range(N):
        A = ReadInt(1)[0]
        if ms.empty():
            ms.add(A)
            continue
        if A <= ms.min():
            ms.add(A)
        else:
            b = ms.lower_bound(A)
            if b is None:
                ms.pop_max()
                ms.add(A)
            else:
                c = ms.prev(b)
                ms.remove(c)
                ms.add(A)
    print(ms.size())

if __name__ == "__main__":
    main()