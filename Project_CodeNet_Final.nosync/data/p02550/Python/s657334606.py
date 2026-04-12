import sys
readline = sys.stdin.readline

N,X,M = map(int,readline().split())
nex = [0] * M
sums = [0] * M

for i in range(M):
  nex[i] = i * i % M
  sums[i] = i

ans = 0
while N:
  if N & 1:
    ans += sums[X]
    X = nex[X]
  sums = [sums[i] + sums[nex[i]] for i in range(M)]
  nex = [nex[nex[i]] for i in range(M)]
  N >>= 1
  
print(ans)