H,W=list(map(int,input().split()))
A=[list(input()) for i in range(H)]
a=0
for i in range(H):
    for j in range(W):
        if A[i][j]=="#":
            a+=1

if a==H+W-1:
    print("Possible")
else:
    print("Impossible")