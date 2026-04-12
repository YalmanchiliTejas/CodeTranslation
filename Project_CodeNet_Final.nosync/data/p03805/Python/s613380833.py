n,m = map(int,input().split())

list_l = []
list_r = []
seen = [0]*n
sta = []
count = 0
sta.append(1)

for i in range(m):
  temp = list(map(int,input().split()))
  list_l.append(temp[0])
  list_r.append(temp[1])
  
def dfs(count):
  a = sta.pop()
  seen[a-1] = 1
  
  if not (0 in seen):
    count = count + 1

  for i,x in enumerate(list_l):
    if x == a:
      next_num = list_r[i]
      if seen[next_num-1] == 0:
        sta.append(next_num)
        count = dfs(count)
        seen[next_num-1] = 0
    
  for i,x in enumerate(list_r):
    if x == a:
      next_num = list_l[i]
      if seen[next_num-1] == 0:
        sta.append(next_num)
        count = dfs(count)
        seen[next_num-1] = 0
      
  return count

ans = dfs(0)
print(ans)