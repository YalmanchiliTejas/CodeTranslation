import itertools
n,m = map(int,input().split())
M = [[0] * n for i in range(n)]

for i in range(m):
  a,b = map(int,input().split())
  M[a-1][b-1] = 1
couse = list(itertools.permutations(range(n)))
result = 0
#M = np.array(M)
for c in couse:
  con = 0
  if(c[0] == 0):
    for i in range(len(c)-1):
      if(M[c[i]][c[i+1]] == 1 or M[c[i+1]][c[i]] == 1):
        con += 1
        #print(c[i],c[i+1])
    if (len(c)-1 == con):
      result += 1
print(result)