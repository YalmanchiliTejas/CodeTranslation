h, w = tuple(map(int, input().split()))
grid = [list(input()) for _ in range(h)]

rm_h = [i for i, line in enumerate(grid) if all([x == '.' for x in line])]

rm_w = [i for i in range(w) if all([grid[j][i] == '.' for j in range(h)])]

arc_grid = [[grid[j][i] for i in range(w) if not i in rm_w] for j in range(h) if not j in rm_h]
for i in range(h-len(rm_h)):
  for j in range(w-len(rm_w)):
    print(arc_grid[i][j], end='')
  print('')