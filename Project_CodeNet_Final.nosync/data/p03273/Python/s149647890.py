h,w = map(int,input().split())
grid = [input() for i in range(h)]

whiteh = []
whitew = []
for i in range(h):
  if grid[i] == "."*w:
    whiteh.append(i)

for i in reversed(whiteh):
  grid.pop(i)
h -= len(whiteh)

grid2 = [""]*w
for i in range(h):
  for j in range(w):
    grid2[j] += grid[i][j]    
    
for i in range(w):
  if grid2[i] == "."*h:
    whitew.append(i)    
    
for i in reversed(whitew):
  grid2.pop(i)
w -= len(whitew)

gridans = [""]*h
for i in range(w):
  for j in range(h):
    gridans[j] += grid2[i][j] 

for i in range(h):
  print(gridans[i])