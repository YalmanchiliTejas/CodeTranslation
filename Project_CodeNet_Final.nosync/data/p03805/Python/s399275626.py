import sys
input = sys.stdin.readline
import itertools

N, M = map(int, input().split())
ab = [list(map(int, input().split())) for n in range(M)]
branch = [[False]* N for n in range(N)]

for m in range(M):
  a = ab[m][0] - 1
  b = ab[m][1] -1 
  branch[a][b] = True
  branch[b][a] = True

ans = 0
pattern = itertools.permutations(range(1, N+1),N)
for l in pattern:
  if l[0] != 1:
    continue
  for n in range(N):
    if n == N - 1:
      ans += 1
      break
    p = l[n] -1
    np = l[n+1] -1
    if not(branch[p][np]):
      break

print(ans)