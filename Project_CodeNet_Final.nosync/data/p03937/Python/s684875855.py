H,W=map(int,input().split())
A=[input() for i in range(H)]

IsPossible=True
res=[]
for y in range(H):
    left=-1
    right=0
    for x in range(W):
        if A[y][x]=='#':
            if left<0:
                left=x
                right=x
            else:
                if x-right==1:
                    right=x
                else:
                    IsPossible=False
                    break
    res.append((left,right))

for y in range(1,H):
    if res[y-1][1]!=res[y][0]:
        IsPossible=False

if IsPossible:
    print('Possible')
else:
    print('Impossible')