import itertools
n,m = map(int,input().split())
tf = [[False for _ in range(n)] for _ in range(n)]
for _ in range(m):
  ai,bi = map(int,input().split())
  ai -= 1
  bi -= 1
  tf[ai][bi] = True
  tf[bi][ai] = True
l = [i for i in range(1,n)]
c = 0
for v in itertools.permutations(l,n-1):
    if tf[0][v[0]] == True:
      flag = True
      for i in range(n-2):
        if tf[v[i]][v[i+1]] == False:
          flag = False
          break
      if flag:
        c += 1
print(c)