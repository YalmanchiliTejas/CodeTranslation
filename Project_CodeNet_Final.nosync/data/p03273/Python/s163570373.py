H, W = map(int, input().split())
a = [input() for _ in range(H)]
grid = [[True]*W for _ in range(H)]
for i in range(H):
    flag = True
    for j in range(W):
        if a[i][j] == '#':
            flag = False
    if flag:
        for k in range(W):
            grid[i][k] = False

for i in range(W):
    flag = True
    for j in range(H):
        if a[j][i] == '#':
            flag = False
    if flag:
        for k in range(H):
            grid[k][i] = False  

for i in range(H):
    for j in range(W):  
        if grid[i][j]:
            print(a[i][j], end="")
    print()
        
