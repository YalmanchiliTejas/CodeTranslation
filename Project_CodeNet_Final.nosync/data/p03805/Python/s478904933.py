import  itertools
n,m = map(int,input().split())
matrix = [[0]*n for _ in range(n)]

for i in range(m):
 a,b = map(int,input().split())
 matrix[a-1][b-1] = 1
 matrix[b-1][a-1] = 1
#print(matrix)
cnt = 0

for each in itertools.permutations(range(n)):
  if each[0] != 0:
     break
  factor = 1
  for i in range(n-1):
    factor *= matrix[each[i]][each[i+1]]
  cnt += factor
print(cnt)