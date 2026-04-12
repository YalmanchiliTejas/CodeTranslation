H, W = map(int, input().split())
grid = []
for i in range(H):
    a = input()
    assert len(a) == W
    grid.append(a)

whiterow = [all(c == '.' for c in row) for row in grid]
whitecol = [all(row[i] == '.' for row in grid) for i in range(W)]

for r, row in enumerate(grid):
    if whiterow[r]: continue
    comp = [c for i, c in enumerate(row) if not whitecol[i]]
    print(''.join(comp))
