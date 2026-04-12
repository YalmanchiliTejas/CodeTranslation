H,W=map(int,input().split())
a=[list(input()) for i in range(H)]
flag=True
while flag:
    if ['.']*W in a:
        a.remove(['.']*W)
        H-=1
    else:
        flag=False
flag=True
b=[[row[i] for row in a] for i in range(W)]
while flag:
    if ['.']*H in b:
        b.remove(['.']*H)
        W-=1
    else:
        flag=False
a=[[row[i] for row in b] for i in range(H)]
for i in range(H):
    s=''.join(a[i])
    print(s)