h,w=map(int,input().split())
a=[]
for i in range(h):
    li=list(input())
    a.append(li)
for i in range(w):
    b=0
    for j in range(h):
        if a[j][i]=='.':
            b+=1
    if b==h:
        for k in range(h):
            a[k][i]=''
for j in range(h):
    if a[j].count('#')!=0:
        print(''.join(a[j]))
