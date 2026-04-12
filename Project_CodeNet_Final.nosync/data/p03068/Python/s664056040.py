# Tenka1 Programmer Beginner Contest 2019
# https://atcoder.jp/contests/tenka1-2019-beginner
# 
# 

import sys

s2nn = lambda s: [int(c) for c in s.split(' ')]
ss2nn = lambda ss: [int(s) for s in list(ss)]
ss2nnn = lambda ss: [s2nn(s) for s in list(ss)]
i2s = lambda: sys.stdin.readline().rstrip()
i2n = lambda: int(i2s())
i2nn = lambda: s2nn(i2s())
ii2ss = lambda n: [sys.stdin.readline() for _ in range(n)]
ii2nnn = lambda n: ss2nnn(ii2ss(n))

def main(N, S, K):
    S = list(S)
    s = S[K-1]
    for i in range(N):
        if S[i] != s:
            S[i] = '*'
    S = ''.join(S)
    print(S)

N = i2n()
S = i2s()
K = i2n()
main(N, S, K)
