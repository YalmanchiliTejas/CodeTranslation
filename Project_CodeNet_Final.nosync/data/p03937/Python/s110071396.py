H, W = map(int, input().split())
A = [[i for i in input()]for j in range(H)]
B = [["." for i in range(W)]for i in range(H)]
B[0][0] = "#"
x = 0; y = 0
while(True):
    if x == H-1 and y<W-1:
        if A[x][y+1] == "#":
            y += 1
        else:
            break
    elif x<H-1 and y == W-1:
        if A[x+1][y] == "#":
            x += 1
        else:
            break
    elif x==H-1 and y==W-1:
        B[x][y] = "#"
        break
    else:
        if A[x][y+1] == "#":
            y += 1
        elif A[x+1][y] == "#":
            x += 1
        else:
            break
    B[x][y] = "#"
for i in range(H):
    for j in range(W):
        if A[i][j]!=B[i][j]:
            print("Impossible")
            exit()
print("Possible")
