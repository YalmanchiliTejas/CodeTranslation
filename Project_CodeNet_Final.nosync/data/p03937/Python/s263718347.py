H, W = [int(x) for x in input().split()]
A = [input() for i in range(0, H)]
i, j = 0, 0
H, W = H-1, W-1
moveX = [1, 0, -1, 0]
moveY = [0, 1, 0, -1]
while True:
    count = 0
    for k in range(0, 4):
        ii = i+moveX[k]
        jj = j+moveY[k]
        if 0 <= ii and ii <= H and 0 <= jj and jj <= W:
            if A[ii][jj] == '#':
                count += 1
    invalid = 2 if (not (i==0 and j==0)) and (not(i==H and j==W)) else 1  
    if count > invalid:
        print("Impossible")
        break
    if i < H and A[i+1][j] == '#':
        i = i+1
        continue
    if j < W and A[i][j+1] == '#':
        j = j+1
        continue
    if i == H and j == W:
        print("Possible")
        break
    else:
        print("Impossible")
        break
