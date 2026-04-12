import itertools

N,M = (int(i) for i in input().split())
li = [[None]*N for i in range(N)]
cnt = 0

for i in range(N):
  li[i][i] = 1

for j in range(M):
  a,b = (int(i)-1 for i in input().split())
  li[a][b] = 1
  li[b][a] = 1

for i in itertools.permutations(range(1,N)):
  if li[i[0]][0] == 1:
    flag = True
    for j in range(1,N-1):
      if li[i[j]][i[j-1]] == None:
        flag = False
        break
    if flag:
      cnt += 1

print(cnt)