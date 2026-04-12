h,w = map(int, input().split())
cells = [[c for c in row] for row in [input() for i in range(h)] if '#' in row]

h = len(cells)
for i in range(w-1, -1, -1):
  has_block = False
  for j in range(h):
    if cells[j][i] == '#':
      has_block = True
      break
  if not has_block:
    for j in range(h):
      cells[j].pop(i)
  

for row in cells:
  print(''.join(row))
