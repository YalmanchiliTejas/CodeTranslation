hw=list(map(int,input().split()))
h=hw[0]
w=hw[1]
a=[[] for i in range(h)]
b=[]
for i in range(h):
    a[i] = list(str(input()))
for i in range(h):
    y=True
    for j in range(w):
        if y and a[i][j]==".":
            y=True
        else:
            y=False
    if not(y):
        b.append(a[i][:])
c=[[] for i in range(len(b))]
e=[0 for i in range(len(b[0]))]
for i in range(len(b[0])):
    t=True
    for j in range(len(b)):
        if t and b[j][i]==".":
            t=True
        else:
            t=False
    e[i]=t
for i in range(len(b)):
    for j in range(len(b[0])):
        if not(e[j]):
            c[i].append(b[i][j])
for i in range(len(c)):
    print("".join(c[i]))