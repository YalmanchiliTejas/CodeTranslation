#  --*-coding:utf-8-*--

import math

def f(m, k):
    if k > m:
        return 0

    return math.factorial(m)//(math.factorial(m-k)*math.factorial(k))*(9**k)


def g(N, k, i):
    if k == 0:
        return 1
        
    M = len(N)-i

    if M < k:
        return 0

    n = int(N[i])

    s = 0

    if n > 0:
        s += f(M-1, k) + (n-1)*f(M-1, k-1) + g(N, k-1, i+1)
    else:
        s += g(N, k, i+1)

    return s


N = input()
K = int(input())
print(g(N, K, 0))
