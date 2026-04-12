
import numpy as np
from functools import *
import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline


def array(size, init=0):
    return [[init for j in range(size[1])] for i in range(size[0])]


def acinput():
    return list(map(int, input().split(" ")))


def II():
    return int(input())


def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)


def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m


K = 10**9+7
N = II()
a = np.array(acinput())
a = a[a != 0]
N = len(a)
s1 = 0
for i in range(N):
    s1 += a[i]
    s1 %= K

s1 %= K

# s1%=K
# s2 = s1
s = (s1*s1) % K
T = 0
for i in range(N):
    T += a[i]*a[i]
    T %= K
# s += K

tmp = modinv(2, K)
s += K
print((s-T)*tmp % K)