h, w = map(int,input().split())
grid = [list(input()) for _ in range(h)]

for i in range(h-1):
    for j in range(1, w):
        if grid[i][j] == "#":
            if grid[i+1][j-1] == "#":
                print("Impossible")
                exit()

print("Possible")