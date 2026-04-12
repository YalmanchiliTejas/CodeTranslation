import itertools

n, m = map(int, input().split())

side = [[] for k in range(n+1)] 

for i in range(m):
  a, b = map(int, input().split())
  side[a].append(b)
  side[b].append(a)

ans = 0  
for i in list(itertools.permutations(range(1, n+1), n)):
  if i[0] != 1:
    continue
  for j in range(n-1):
    if not i[j+1] in side[i[j]]:
      break
    if j == n-2:
      ans +=1
print(ans)
  
  
    

