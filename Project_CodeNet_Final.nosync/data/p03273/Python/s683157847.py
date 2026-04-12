import copy
H,W=map(int,input().split())
a=[input() for i in range(H)]
flag=True
while flag:
    if '.'*W in a:
        a.remove('.'*W)
        H-=1
    else:
        flag=False
b=[0]*H
f=True
while f:
    c=copy.deepcopy(a)
    g=False
    for i in range(W):# i列
        if g:
            break
        for j in range(H):
            b[j]=a[j][i]
        if ''.join(b)=='.'*H:
            for k in range(H):
                s=list(a[k])
                del s[i]
                a[k]=''.join(s)
            W-=1
            g=True
            break
    if c==a:
        f=False
for i in range(H):
    s=''.join(a[i])
    print(s)