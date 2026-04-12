H,W=map(int,input().split())
grid=[""]*H
del_list=[[],[]]
for i in range(H):
  grid[i]=list(input())
  if grid[i]==["." for j in range(W)]:
    del_list[0].append(i)

for i in range(W):
  tmp=[grid[x][i] for x in range(H)]
  if tmp == ["." for j in range(H)]:
    del_list[1].append(i)
    
for i in reversed(range(len(del_list[0]))):
  grid.pop(del_list[0][i])
  
for i in reversed(range(len(del_list[1]))):
  for j in range(len(grid)):
    grid[j].pop(del_list[1][i])

for i in range(len(grid)):
  print("".join(grid[i]))