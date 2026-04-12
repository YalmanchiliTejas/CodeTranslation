from itertools import permutations
n, m = map(int, input().split())
d = [[] for _ in range(n)]
ans = 0
for i in range(m):
  a, b = map(int, input().split())
  d[a - 1].append(b - 1)
  d[b - 1].append(a - 1)
l = permutations(range(1, n))
for i in l:
  pre = 0
  c = 0
  for j in i:
    if not j in d[pre]:
      break
    c += 1
    pre = j
  if c == n-1:
    ans += 1
print(ans)