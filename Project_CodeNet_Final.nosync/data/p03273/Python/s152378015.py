h,w=map(int,input().split())
alist=[]
numans=list(range(h))
for i in range(h):
    a=list(input())
    alist.append(a)
for i in range(h):
    if alist[h-i-1].count(".")==w:
        numans.remove(h-i-1)
lena=len(alist)
yn=0
for i in range(w):
    for j in range(lena):
        if alist[j][w-i-1]!=".":
            yn=1
    if yn==0:
        for j in range(lena):
            del alist[j][w-i-1]
    yn=0
c=""
lena=len(alist[0])
for i in numans:
    for j in range(lena):
        c+=alist[i][j]
    print(c)
    c=""
