import sys

stdin = sys.stdin

mod = 1000000007

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

n, m, k = na()

def invl(a, mod):
    b = mod
    p = 1; q = 0
    while b > 0:
        c = a // b
        a, b = b, a%b
        p, q = q, p-c*q
    return p + mod if p < 0 else p

num = 1
den = 1
for u in range(k-2):
    num = num * (n*m-2-u) % mod
for u in range(k-2):
    den = den * (1+u) % mod
C = num * invl(den, mod) % mod

# 10 7 6 7 10
# i i-1 .. 0 .. n-1-i
# sum_i (i*(i+1)//2 + (n-1-i)*(n-i)//2)*m
# n*(n+1)*(n+2)//6*2*m

v = n*(n+1)*(n-1)//3*m*m + m*(m+1)*(m-1)//3*n*n
v *= C
print(v*invl(2,mod)%mod)
