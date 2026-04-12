H, W = map(int, input().split())

grid = []
for i in range(H):
    grid.append(input())

grid_h = list(filter(lambda h: any([_ == '#' for _ in h]), grid))
remove_list = []
for w in range(W):
    for i, g in enumerate(grid_h):
        if g[w] == '#':
            break
        if i == len(grid_h) - 1:
            remove_list.append(w)
grid_hw = []
for g in grid_h:
    s = ''
    for i, c in enumerate(g):
        if i not in remove_list:
            s += c
    grid_hw.append(s)
for g in grid_hw:
    print(g)