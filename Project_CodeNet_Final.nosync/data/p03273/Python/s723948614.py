H,W=map(int,input().split())
a=[[] for _ in range(H)]

for i in range(H):
    a[i]=input()
    
ans=[[0]*W for _ in range(H)]

for i in range(H):
    if a[i]=="."*W:
        continue
    else:
        for j in range(W):
            if a[i][j]==".":
                ans[i][j]=1
            else:
                ans[i][j]=2

        
        
for j in range(W):
    if 2 in [row[j] for row in ans]:
        continue
    else:
        for i in range(H):
            ans[i][j]=0
        
for i in range(H):
    temp=""
    for j in range(W):
        if ans[i][j]==1:
            temp+="."
        elif ans[i][j]==2:
            temp+="#"
    if temp!="":
        print(temp)
        