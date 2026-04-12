import itertools

n,m = [int(i) for i in input().split()]

chk = [[0]*n for i in range(n)]
for i in range(m):
  a,b = [int(i) for i in input().split()]
  chk[a-1][b-1] = 1
  chk[b-1][a-1] = 1

ans = 0

for i in itertools.permutations(range(n),n):
  if i[0] == 0:
    for j in range(n):
      if j == n-1:
        ans += 1
        break
      if chk[i[j]][i[j+1]] != 1:
        break
print(ans)