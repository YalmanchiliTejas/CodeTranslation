H,W = map(int,input().split())
A = [input().strip() for _ in range(H)]
cnt_row = 0
for i in range(H):
    cnt_row += A[i].count("#")-1
cnt_col = 0
for j in range(W):
    cnt = 0
    for i in range(H):
        if A[i][j]==("#"):
            cnt += 1
    cnt_col += cnt-1
if cnt_row==W-1 and cnt_col==H-1:
    print("Possible")
else:
    print("Impossible")