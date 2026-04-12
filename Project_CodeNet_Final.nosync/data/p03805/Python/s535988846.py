import itertools
n,m = map(int,input().split())
info = [list(map(int,input().split())) for i in range(m)]

tree= [[] for i in range(n)]
for i in range(m):
  tree[info[i][0]-1].append(info[i][1]-1)
  tree[info[i][1]-1].append(info[i][0]-1)

num = []  
for i in range(n):
  num.append(i)
  
ans = 0
for li in itertools.permutations(num, n):
  flag =True
  if li[0]==0:
    for i in range(n-1):
      if li[i+1] not in tree[li[i]]:
        flag =False
    if flag:
      ans = ans +1
    
  else:
    print(ans)
    exit()