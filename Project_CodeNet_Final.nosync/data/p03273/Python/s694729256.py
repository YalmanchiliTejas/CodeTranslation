import sys
H, W = map(int, input().split())

grid = []
dot_h = []
sharp_h = []
dot_w = []
sharp_w = []

for h in range(H):
    line = input()
    line = line[:W]
    grid.append(line)
    if line.count('.') == W:
        dot_h.append(h)
    # if line.count('#') == W:
    #     sharp_h.append(h)
for w in range(W):
    dot_c = 0
    sharp_c = 0
    for h in range(H):
        if grid[h][w] == '.':
            dot_c += 1
        # if grid[h][w] == '#':
        #     sharp_c += 1
    if dot_c == H:
        dot_w.append(w)
    if sharp_c == H:
        sharp_w.append(w)
    
for h in range(H):
    if h in dot_h or h in sharp_h:
        continue
    for w in range(W):
        if w in dot_w or w in sharp_w:
            continue
        # print(grid[h][w], end="")
        sys.stdout.write(grid[h][w])
    print('')