import copy
h,w=map(int,input().split())
a=[]
deleted=0
for i in range(h):
    l=list(input())
    for j in l:
        if j=='#':
            a.append(l)
            break
    else:
        deleted+=1
h-=deleted

deleted=0
b=copy.deepcopy(a)
for i in range(w):
    for j in range(h):
        if a[j][i]=='#':
            break
    else:
        for j in range(h):
            b[j].pop(i-deleted)
        deleted+=1

s=''
for i in b:
    s+=''.join(i)+'\n'
print(s)