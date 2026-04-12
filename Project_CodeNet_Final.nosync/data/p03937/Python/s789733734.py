H,W=map(int,input().split())
A=[]
count=0
for i in range(H):
    a=input()
    A.append(a)
chk=[[0 for _ in range(W)] for i in range(H)]
if A[0][0]=="#":
    chk[0][0]=1
    count+=1
else:
    print("Impossible")
    exit()

for i in range(H):
    for j in range(W):
        if i==0 and j==0:
            continue
        if A[i][j]==".":
            continue
        count+=1
        if i!=0:
            if A[i-1][j]=="#":
                if chk[i-1][j]!=0:
                    chk[i][j]=1
        if j!=0:
            if A[i][j-1]=="#":
                if chk[i][j-1]!=0:
                    chk[i][j]=1
if count!=(W+H-1):
    print("Impossible")
    exit()
if chk[-1][-1]==1:
    print("Possible")
else:
    print("Impossible")