H,W=map(int,input().split())
L=[list(input()) for _ in range(H)]
for _ in range(H+W):
    ans=[]
    res=[]
    l=[]
    for s in L:
        if '#' in s:
            l.append(s)
    for z in zip(*l):
        if '#' in z:
            res.append(z)
    for z in zip(*res):
        ans.append(list(z))
    L=ans.copy()
for t in L:
  print(''.join(t))