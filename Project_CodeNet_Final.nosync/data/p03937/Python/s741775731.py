H,W = map(int,input().split())
A = [list(input().strip()) for _ in range(H)]
x = [0,0]
A[0][0] = "."
while True:
    if x[0]==H-1 and x[1]==W-1:break
    if x[0]<H-1 and A[x[0]+1][x[1]]=="#":
        A[x[0]+1][x[1]]="."
        x = [x[0]+1,x[1]]
    elif x[1]<W-1 and A[x[0]][x[1]+1]=="#":
        A[x[0]][x[1]+1]="."
        x = [x[0],x[1]+1]
    elif (x[0]<H-1 and A[x[0]+1][x[1]]==".") and (x[1]<W-1 and A[x[0]][x[1]+1]=="."):
        break
    elif (x[0]==H-1 and x[1]<W-1 and A[x[0]][x[1]+1]==".") or (x[1]==W-1 and x[0]<H-1 and A[x[0]+1][x[1]]=="."):
        break
flag = 0
for i in range(H):
    for j in range(W):
        if A[i][j]=="#":
            flag = 1
            break
    if flag==1:break
if flag==0:
    print("Possible")
else:
    print("Impossible")