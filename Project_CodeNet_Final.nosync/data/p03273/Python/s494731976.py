H, W = map(int, input().split())
a = [[j for j in input()] for i in range(H)]

row, col = [False] * H, [False] * W
for i in range(H):
    for j in range(W):
        if a[i][j] == "#":
            row[i] = col[j] = True

for i in range(H):
    if row[i]:
        for j in range(W):
            if col[j]:
                print(a[i][j], end="")
        print()
