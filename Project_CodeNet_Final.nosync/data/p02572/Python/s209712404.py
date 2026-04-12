#!python3.8
# -*- coding: utf-8 -*-
# abc177/abc177_c
import sys

s2nn = lambda s: [int(c) for c in s.split(' ')]
ss2nn = lambda ss: [int(s) for s in list(ss)]
ss2nnn = lambda ss: [s2nn(s) for s in list(ss)]
i2s = lambda: sys.stdin.readline().rstrip()
i2n = lambda: int(i2s())
i2nn = lambda: s2nn(i2s())
ii2ss = lambda n: [i2s() for _ in range(n)]
ii2nn = lambda n: ss2nn(ii2ss(n))
ii2nnn = lambda n: ss2nnn(ii2ss(n))

P = 10**9 + 7

def main():
    N = i2n()
    A = i2nn()
    B = [None] * (N - 1)
    B[-1] = A[-1]
    for i in range(2, N):
        B[-i] = (A[-i] + B[-i+1]) % P
    ans = 0
    for i in range(N - 1):
        ans += (A[i] * B[i]) % P
    print(ans % P)
    return

main()
