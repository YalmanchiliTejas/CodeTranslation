h,w = map(int, input().split())
a = [None]*h
for i in range(h):
    a[i] = list(input())

valid_h=[]
valid_w=[]

for i in range(h):
    flg=False
    for j in range(w):
        if a[i][j] =="#":
            flg=True
    if flg:
        valid_h.append(i)

for j in range(w):
    flg=False
    for i in range(h):
        if a[i][j] =="#":
            flg=True
    if flg:
        valid_w.append(j)

ans=[]
for i in range(h):
    if not i in valid_h:
        continue

    tmp=[]
    for j in range(w):
        if j in valid_w:
            tmp.append(a[i][j])
    ans.append(tmp)

for a in ans:
    print(*a,sep="")