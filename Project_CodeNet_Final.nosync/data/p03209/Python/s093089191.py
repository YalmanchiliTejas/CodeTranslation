#ABC115D-Christmas.py

from sys import stdin

input = stdin.readline

N, X = list(map(int, input().split()))

def l(n):
    return 2**(n+2)-3

def p(n):
    return 2**(n+1)-1

def f(N, X):
    if X == 0:
        return 0
    elif X <= l(N-1) + 1:
        return f(N-1,X-1)
    elif X == l(N-1) + 2:
        return 1 + p(N-1)
    elif X <= 2 * l(N-1) + 2:
        return 1 + p(N-1) + f(N-1, X-l(N-1)-2)
    else:
        return 1 + 2 * p(N-1)

print(f(N,X))
