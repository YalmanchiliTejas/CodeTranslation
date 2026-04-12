import itertools
n, m = map(int, input().split())

node = [[False]*n for _ in range(n)]
for i in range(m):
  a, b = map(int, input().split())
  node[a-1][b-1] = True
  node[b-1][a-1] = True

ans = 0
for value in itertools.permutations([int(x) for x in range(1, n)]):
  if not node[0][value[0]]:
    continue
  flag = True
  for i in range(n-2):
    if not node[value[i]][value[i+1]]:
      flag = False
  if flag:
    ans += 1

print(ans)