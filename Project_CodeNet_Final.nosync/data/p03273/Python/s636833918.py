H,W=map(int,input().split())
G=[list(input()) for i in range(H)]
hcnt,wcnt=set(),set()
for i in range(H):
    ok=True
    for j in range(W):
        if(G[i][j]=='#'):
            ok=False
            break
    if(ok):
        hcnt.add(i)
for j in range(W):
    ok=True
    for i in range(H):
        if(G[i][j]=='#'):
            ok=False
            break
    if(ok):
        wcnt.add(j)

for i in range(H):
    cnt=0
    if(i in hcnt):
        continue
    for j in range(W):
        if(j in wcnt):
            continue
        print(G[i][j],end='')
        cnt+=1
    if(cnt>0):
        print()