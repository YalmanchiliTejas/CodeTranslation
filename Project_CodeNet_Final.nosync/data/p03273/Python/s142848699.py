H,W=map(int,input().split())
a=[input() for i in range(H)]
useh=[True]*H
usew=[True]*W
for h in range(H):
    cnt=0
    for w in range(W):
        if a[h][w]=='.':
            cnt+=1
    if cnt==W:
        useh[h]=False
for w in range(W):
    cnt=0
    for h in range(H):
        if a[h][w]=='.':
            cnt+=1
    if cnt==H:
        usew[w]=False
for h in range(H):
    if useh[h]:
        for w in range(W):
            if usew[w]:
                print(a[h][w],end='')
        print()
