h,w=map(int,input().split())
a=[input() for i in range(h)]
b=[]

for i in range(h):
    if a[i].count(".")==w:
        b.append(i)

for i in reversed(b):
    a.pop(i)

h-=len(b)
for i in range(w-1,-1,-1):
    flag=True
    for j in range(h-1,-1,-1):
        if a[j][i]=="#":
            flag=False
    if flag:
        for k in range(h-1,-1,-1):
            a[k]=a[k][:i]+a[k][i+1:]

for i in range(h):
    print(a[i])