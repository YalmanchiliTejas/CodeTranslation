H,W = map(int,input().split())
A = [input().strip() for _ in range(H)]
r = 0
c = 0
for i in range(H):
    for j in range(1,W):
        if A[i][j]==A[i][j-1]=="#":
            r += 1
for j in range(W):
    for i in range(1,H):
        if A[i][j]==A[i-1][j]=="#":
            c += 1
if r==W-1 and c==H-1:
    print("Possible")
else:
    print("Impossible")