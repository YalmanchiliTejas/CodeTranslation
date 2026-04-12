H, W = map(int, input().split())
grid = [list(str(input())) for _ in range(H)]

for h in range(H):
    cnt = sum([0 if i=='.' else 1 for i in grid[h]])
    if cnt==0:
        grid[h] = [0]*W

for w in range(W):
    cnt = sum([0 if grid[h][w] in ('.', 0) else 1 for h in range(H)])
    if cnt == 0:
        for h in range(H):
            grid[h][w] = 0

for g in grid:
    string = [s for s in g if not s==0]
    if len(string)==0:
        continue
    print(''.join(string))