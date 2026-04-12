# AtCoder Beginner Contest 124
# https://atcoder.jp/contests/abc124
import sys

s2nn = lambda s: [int(c) for c in s.split(' ')]
ss2nn = lambda ss: [int(s) for s in list(ss)]
ss2nnn = lambda ss: [s2nn(s) for s in list(ss)]
i2s = lambda: sys.stdin.readline().rstrip()
i2n = lambda: int(i2s())
i2nn = lambda: s2nn(i2s())
ii2ss = lambda n: [sys.stdin.readline() for _ in range(n)]
ii2nnn = lambda n: ss2nnn(ii2ss(n))

def main(N, H):
    n = 0
    h = 0
    for i in range(N):
        if h <= H[i]:
            n += 1
            h = H[i]
    print(n)

N = i2n()
H = i2nn()
main(N, H)
