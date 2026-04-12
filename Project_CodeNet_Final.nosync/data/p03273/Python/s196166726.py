import sys
h,w=map(int,input().split())
l1=[]
l2=[]
a=[]
for i in range(h):
    l1.append(list(map(str,input())))
for i in range(len(l1)):
    if set(l1[i])!={'.'}:
        l2.append(l1[i])
for k in range(len(l2[0])):
    c=0
    for i in range(len(l2)):
        if l2[i][k]=='.':
            c+=1
            continue
        else:
            break
    if c!=len(l2):
        a.append(k)
for i in range(len(l2)):
    b=''
    for k in a:
        b+=l2[i][k]
    print(b)

