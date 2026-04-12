H,W=map(int,input().split())
bwmap=[]
hlist=[]
for i in range(H):
    a=input()
    if a=='.'*W:
        bwmap.append(a)
    else:
        hlist.append(i)
        bwmap.append(a)
wlist=[]
for j in range(W):
    for i in range(H):
        if bwmap[i][j]=='#' :
            wlist.append(j)
            break
        if i==H-1:
            pass
result=[]
for i in hlist:
    res=''
    for j in wlist:
        res=res+bwmap[i][j]
    print(res)