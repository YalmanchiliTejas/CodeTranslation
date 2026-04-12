H, W = map(int, input().split())
A = [list(input())for _ in range(H)]

cnt_j = 0
for i in range(H):
    for j in range(W):
        if(A[i][j] == "#"):
            if(cnt_j <= j):
                cnt_j = j
            else:
                print("Impossible")
                quit()
else:
    print("Possible")