H,W=map(int,input().split())
A=[list(input()) for _ in range(H)]
x=0
y=0
flag=1
cnt=0
for i in range(H):
    for j in range(W):
        if A[i][j]=="#":
            cnt=cnt+1

if cnt==W+H-1:
    print("Possible")
else:
    print("Impossible")