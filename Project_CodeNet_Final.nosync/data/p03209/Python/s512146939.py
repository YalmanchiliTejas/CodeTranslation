import sys
sys.setrecursionlimit(10**5)

n, x = map(int, input().split())

def func(x, n):
    if n == 0:
        return 1
    if x <= 1:
        return 0
    elif 2 <= x <= 2**(n+1)-2:
        return func(x-1, n-1)
    elif x == 2**(n+1)-1:
        return 2**n-1+1
    elif 2**(n+1) <= x:
        return 2**n-1+1+func(x-(2**(n+1)-1), n-1)

print(func(x, n))
