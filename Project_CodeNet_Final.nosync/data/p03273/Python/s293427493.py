import sys
H,W=map(int,input().split())
a=list(sys.stdin)

q,w=[1]*H,[1]*W
for i in range(H):
    for j in range(W):
        if a[i][j]=='#':
            q[i]=w[j]=0

ans=''
for i in range(H):
    if q[i]:
        continue
    row=''
    for j in range(W):
        if w[j]:
            continue
        row+=a[i][j]
    ans+=row+'\n'
    

print(ans)
