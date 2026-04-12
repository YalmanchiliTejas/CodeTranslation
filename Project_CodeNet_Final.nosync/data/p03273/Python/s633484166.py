import numpy as np
from sys import stdin
H,W=[int(x) for x in stdin.readline().rstrip().split()]
data=[]
for i in range(H):
    data.append([ 1 if x == "#" else 0 for x in list(input())])
data=np.array(data)
index_col=[]
for j in range(W):
    if sum(data[:,j]) == 0:
        index_col.append(j)
data=np.delete(data, index_col, 1)

index_row=[]
for k in range(H):
    if sum(data[k]) == 0:
        index_row.append(k)
data=np.delete(data,index_row,0)
for l in data:
    tmp=""
    for m in l:
        if m == 1:
            tmp=tmp+"#"
        else:
            tmp=tmp+"."
    print(tmp)