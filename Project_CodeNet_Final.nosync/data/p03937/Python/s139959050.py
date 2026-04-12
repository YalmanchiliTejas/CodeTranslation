h, w = map(int, input().split())
a = [input() for i in range(h)]
for i in range(h-1):
    for j in range(1,w):
        if a[i][j] == "#":
            if a[i+1][j-1] == "#":
                print("Impossible")
                exit()
print("Possible")
