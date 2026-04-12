h,w=map(int,input().split())
a=[input() for _ in range(h)]
sh=set()
sw=set()
for i in range(h):
    ok=True
    for j in range(w):
        if a[i][j]=="#":
            ok=False
    if ok:
        sh.add(i)
for j in range(w):
    ok=True
    for i in range(h):
        if a[i][j]=="#":
            ok=False
    if ok:
        sw.add(j)
#print(sh)
#print(sw)
ans=[]
for i in range(h):
    l=""
    if i in sh:
        continue
    for j in range(w):
        if j in sw:
            continue
        l+=a[i][j]
    ans.append(l)
for c in ans:
    print(c)