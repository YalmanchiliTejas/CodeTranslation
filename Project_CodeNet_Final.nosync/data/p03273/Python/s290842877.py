h,w=map(int,input().split())
a=[list(input())for _ in range(h)]
b=[]
for i in range(h):
    if a[i].count('.')==w:
        continue
    else:
        b.append(a[i])
c=[]
for i in range(w):
    d=[]
    for j in range(len(b)):
        d.append(b[j][i])
    c.append(d)
e=[]
for i in range(w):
    if c[i].count('.')==len(b):
        continue
    else:
        e.append(c[i])
for i in range(len(b)):
    for j in range(len(e)):
        print(e[j][i],end='')
    print()