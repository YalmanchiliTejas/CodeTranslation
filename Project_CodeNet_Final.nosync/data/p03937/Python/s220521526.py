H,W = [int(zz) for zz in input().split()]
map = [list(input()) for _ in range(H)]

r = 0
for j in range(W):
    if map[0][j] == "#":
        r = j
for i in range(1,H):
    flag = 1
    for j in range(W):
        if flag and map[i][j] == "#":
            if r != j:
                print('Impossible')
                exit()
            flag = 0
        elif map[i][j] == "#":
            r = j

print('Possible')
