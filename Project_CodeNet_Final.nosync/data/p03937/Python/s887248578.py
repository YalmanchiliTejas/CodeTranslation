a,b=map(int,input().split())
l=[]
for _ in range(a):
    l1=input()
    l.append(l1)
flag=True
for i in range(b):
    for j in range(a):
        if i>=1 and j!=a-1 and l[j][i]=='#':
            for k1 in range(i):
                for k2 in range(j+1,a):
                    if l[k2][k1]=='#':
                        flag=False
                        break
for i in range(b):
    for j in range(a):
        if i!=b-1 and j>=1 and l[j][i]=='#':
            for k3 in range(j):
                for k4 in range(i+1,b):
                    if l[k3][k4]=='#':
                        flag=False
                        break
if flag==True:
    print('Possible')
else:
    print('Impossible')
    