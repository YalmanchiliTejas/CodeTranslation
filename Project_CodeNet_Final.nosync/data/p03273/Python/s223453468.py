H, W = [int(x) for x in input().split()]

grid = []
for h in range(H):
    a = input()
    if '#' in a:
        grid.append(a)

white = set()
for w in range(W):
    if all(l[w] == '.' for l in grid):
        white.add(w)

H = len(grid)

for l in grid:
    print("".join(l[w] for w in range(W) if w not in white))



