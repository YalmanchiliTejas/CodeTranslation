N, X = (int(i) for i in input().split())

import math

def Pn(n):
    x = 0
    for i in range(n):
        x = x + 2**i
        yield x

Paty = list(Pn(N+1))
Bager = [2*i -1 for i in Paty]

def Ln(n, x):
    if x == 0:
        return 0
    if n == 0:
        return 1

    harf = (Bager[n] + 1) // 2

    if x == harf:
        return 1 + Paty[n-1]

    if x > harf:
        return Ln(n-1, x - 2 - Bager[n-1]) + Paty[n-1] + 1
    else:
        return Ln(n-1, x-1)

print(Ln(N, X))
