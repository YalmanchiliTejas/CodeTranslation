import copy
n,m = map(int, input().split())


paths = [[] for _ in range(n)]
for i in range(m):
  a,b = map(int, input().split())
  paths[a-1].append(b-1)
  paths[b-1].append(a-1)
  
ans = 0

checked = [False for _ in range(n)]


def solve(i, c):
  c[i] = True

  global ans
  if c.count(False) == 0:
    ans += 1
    return
  else:
    for j in paths[i]:
      if c[j] == False: 
        solve(j, copy.deepcopy(c))
        
      

        
solve(0, copy.deepcopy(checked))
print(ans)
    
#print(paths[0])