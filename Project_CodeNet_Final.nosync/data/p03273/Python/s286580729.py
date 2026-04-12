import numpy as np

HW=list(map(int,input().split()))
H=HW[0]
W=HW[1]
a = [input().split() for l in range(H)]

for h in range(H):
    a[h] = [i for i in a[h] if i != '.'*W]

a=list(filter(None, a))
b=[]
for column in range(W):
    tmp=''
    for row in range(len(a)):
        tmp+=a[row][0][column:column+1]
    if tmp=='.'*len(a):
        b.append(column)

tmp2=[]
dellist = lambda items, indexes: [item for index, item in enumerate(items) if index not in indexes]
for j in range(len(a)):
    tmp2.append(list(a[j][0]))
  
for t in range(len(tmp2)):
    tmp2[t]=dellist(tmp2[t],b)
    tmp2[t]=''.join(tmp2[t])
print('\n'.join(tmp2))
