import sys
readline = sys.stdin.readline

N,X,M = map(int,readline().split())

nex = [(i ** 2) % M for i in range(M)]
cum = [i for i in range(M)]

ans = 0
while N:
  if N & 1:
    ans += cum[X]
    X = nex[X]
  cum = [cum[i] + cum[nex[i]] for i in range(M)]
  nex = [nex[nex[i]] for i in range(M)]
  N >>= 1

print(ans)