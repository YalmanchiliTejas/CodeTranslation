import itertools

N,M = map(int, input().split())
g = [[0 for i in range(N)] for j in range(N)]

for i in range(M):
  a,b = map(int, input().split())
  g[a-1][b-1]=1
  g[b-1][a-1]=1

  
jr = list(itertools.permutations(range(2,N+1),N-1))
js = []

for i in jr:
  j = list(i)
  j.insert(0,1)
  js.append(j)

ans = 0
  
for i in range(len(js)):
  hantei = True
  for j in range(N-1):
    a = js[i][j]
    #print(a)
    b = js[i][j+1]
    #print(b)
    if g[a-1][b-1] == 0:
      hantei = False
  if hantei:
    ans += 1

print(ans)