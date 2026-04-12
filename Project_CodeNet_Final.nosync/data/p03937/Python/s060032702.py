import sys

H, W = map(int, sys.stdin.readline().strip().split())

grid = []
for _ in range(H):
    grid.append(list(sys.stdin.readline().strip()))

count = 0
for i in range(H):
    for j in range(W):
        if grid[i][j] == "#":
            count += 1

if count == H + W - 1:
    print("Possible")
else:
    print("Impossible")