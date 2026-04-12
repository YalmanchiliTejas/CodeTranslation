H, W = map(int, input().split())
grid = []
for i in range(H):
    g = input()
    if '#' in g:
        grid.append(g)
        
ans = zip(*[i for i in zip(*grid) if '#' in i])

for j in ans:
  print(*j, sep='')