def sumproductsofpairs(lst):
    total = 0
    psum = 0
    for x in lst:
        total = (total + (psum * x)%mod)%mod
        psum = ((psum)%mod + (x)%mod)%mod
    return total


N=int(input())
array=[int(x) for x in input().split()]

mod=10**9+7
print(sumproductsofpairs(array)%mod)