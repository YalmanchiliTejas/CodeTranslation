h,w=map(int,input().split())
a=[[i for i in input()] for j in range(h)]

x=[False]*w
y=[False]*h

for i in range(h):
    for j in range(w):
        if a[i][j]=='#':
            x[j]=True
            y[i]=True


for i in range(h):
    li=[]
    for j in range(w):
        if x[j]==True and y[i]==True:
            li+=a[i][j]
    if li!=[]:
        print(''.join(li))
