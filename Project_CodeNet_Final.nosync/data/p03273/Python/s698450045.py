h,w=map(int,input().split())
a=[input() for i in range(h)]
b=[]
for i in range(h):
    ans=True
    for j in range(w):
        if a[i][j]=='#':
            ans=False
    if ans:
        b.append(i)
for i in reversed(b):
    a.pop(i)
h-=len(b)
for j in range(w-1,-1,-1):
    ans=True
    for i in range(h-1,-1,-1):
        if a[i][j]=="#":
            ans=False
    if ans:
        for i in range(h-1,-1,-1):
            a[i]=a[i][:j]+a[i][j+1:]
for i in range(h):
    print(a[i])