H,W = map(int, input().split())
A = [list(input()) for _ in range(H)]

i = 0
j = 0
while i < H or j < W:
    if i < H-1 and A[i+1][j] == "#":
        i += 1
        A[i][j] = "."
    elif j < W-1 and A[i][j+1] == "#":
        j += 1
        A[i][j] = "."
    else:
        break

cnt = 0
for i in range(H):
    cnt += A[i].count("#")
if cnt == 1 and i == H-1 and j == W-1:
    print("Possible")
else:
    print("Impossible")