h,w=map(int,input().split())
grid=[]
grid2=[]
grid3=[]
for i in range(h):
  grid.append(list(input().replace(" ","")))
for i in range(len(grid)):
  if grid[i].count('.')==len(grid[i]):
    pass
  else:
    grid2.append(grid[i])
for i in grid2:
  grid3.append([])
for j in range(len(grid2[0])):
  for i in range(len(grid2)):
    if grid2[i][j]=='#':
      for k in range(len(grid3)):
        grid3[k].append(grid2[k][j])
      break
for i in grid3:
  print(''.join(i))