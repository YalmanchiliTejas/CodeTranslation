H,W=(int(i) for i in input().split(' '))
grid=[]
delete_count= 0
pop_count=0
for h in range(H):
  tmp = [char for char in input()]
  if tmp.count('#')!=0:
    grid.append(tmp)
  else:
    delete_count += 1
for w in range(W):
  check = 0
  for h in range(H-delete_count):
    if grid[h][w-pop_count]=='#':
      check = 1
  if check == 0:
    for h in range(H-delete_count):
      del grid[h][w-pop_count]
    pop_count+=1
for h in range(H-delete_count):
  grid[h]=''.join(grid[h])
  print(grid[h])