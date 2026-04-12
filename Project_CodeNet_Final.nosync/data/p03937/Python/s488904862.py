H,W = map(int,input().split())
A = [list(str(input())) for _ in range(H)]
for i in range(H):
  A[i] += '.'
A += [list('.'*(W+1))]
y,x = 0,0
ans = 'Impossible'
while y < H and x < W:
  if A[y+1][x] == '#' and A[y][x+1] == '#':
    break
  elif A[y+1][x] == '#':
    if '#' in A[y][x+1:] or '#' in A[y+1][:x]:
      break
    y += 1
  elif A[y][x+1] == '#':
    x += 1
  else:
    break
  if y == H-1 and x == W-1:
    ans = 'Possible'
    break
print(ans)