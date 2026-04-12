import sys
from itertools import permutations
input = sys.stdin.readline
N, M = map(int,input().rstrip().split())
node = []
for _ in range(M):
  a,b = map(int,input().rstrip().split())
  node.append((a,b))
  node.append((b,a))
ans = 0
for p in permutations(range(1,N+1)):
  flag = True
  if p[0] != 1:
    continue
  for i in range(N-1):
    if (p[i],p[i+1]) not in node:
      flag = False
  if flag:
    ans += 1
print(ans)