H,W=map(int,input().split())
grid=[None]*H
skip_i=set()
skip_j=set()
for i in range(H):
  grid[i]=input()
  if grid[i].count(".")==W:
    skip_i.add(i)

for j in range(W):
  count=0
  for i in range(H):
    if grid[i][j]==".":
      count+=1
  if count==H:
    skip_j.add(j)
    
ans=["" for i in range(H-len(skip_i))]

for i in range(len(grid)):
  if i in skip_i:
    continue
  line=""
  for j in range(len(grid[i])):
    if j in skip_j:
      continue
    line+=(grid[i][j])
  print(line)
