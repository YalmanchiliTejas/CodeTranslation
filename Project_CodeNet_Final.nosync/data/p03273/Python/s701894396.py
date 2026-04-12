import sys
H,W=map(int,input().split())
a=list(sys.stdin)
rs,cs=[1]*H,[1]*W
for i in range(H):
    for j in range(W):
        if a[i][j]=='#':
            rs[i]=cs[j]=0
ans=''
for i in range(H):
    if rs[i]:
        continue
    r=''
    for j in range(W):
        if cs[j]:
            continue
        r+=a[i][j]
    ans+=r+'\n'
print(ans)
