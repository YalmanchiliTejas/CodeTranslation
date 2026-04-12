H,W = map(int,input().split())

a = [input() for _ in range(H)]

for i in range(H):
    for j in range(W):
        if a[i][j] == "#":
            x = i-1
            y = j+1

            if 0 <= x < H and 0 <= y < W:
                if a[x][y] == "#":
                    print("Impossible")
                    exit()
            
            x = i+1
            y = j-1
            if 0 <= x < H and 0 <= y < W:
                if a[x][y] == "#":
                    print("Impossible")
                    exit()
print("Possible")