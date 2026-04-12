h,w=(int(i) for i in input().strip().split(" "))
ar=[]
s=[]
for j in range(h):
    k=[i for i in input().strip()]
    if k==["."]*w:
        pass
    else:
        ar.append(k)

fin=[]
for j in range(w):
    t=[]
    for i in range(len(ar)):
        t.append(ar[i][j])
    if t==["."]*len(t):
        pass
    else:
        fin.append(t)


for j in range(len(fin[0])):
    for i in range(len(fin)):
        print(fin[i][j],end="")
    print()