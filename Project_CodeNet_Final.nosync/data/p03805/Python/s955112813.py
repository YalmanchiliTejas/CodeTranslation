import itertools
N,M = map(int,input().split())

Graph = [[0]*N for _ in range(N)]
for i in range(M):
  a,b = map(int,input().split())
  Graph[a-1][b-1] = 1 
  Graph[b-1][a-1] = 1
  
A = []
for i in range(1,N): A.append(i)

ans = 0
Comb = list(itertools.permutations(A))
for i in range(len(Comb)):
  tmp = list(Comb[i])
  #print(tmp)
  judge = 1
  for j in range(len(tmp)):
    if(j == 0): judge = judge*Graph[0][tmp[j]]
    else: judge = judge*Graph[tmp[j-1]][tmp[j]]
  if(judge == 1): ans += 1
 
print(ans)