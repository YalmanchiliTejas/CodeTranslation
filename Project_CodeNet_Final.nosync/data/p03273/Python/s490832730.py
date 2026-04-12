h,w=map(int,input().split())
a=[]
for i in range(h):
    a.append(input())
r=[False]*h
c=[False]*w

for i in range(h):
    for j in range(w):
        if a[i][j]=='#':
            r[i]=True
            c[j]=True
            
for i in range(h):
    if r[i]==True:
        for j in range(w):
            if c[j]==True:
                print(a[i][j],end='')
        print()