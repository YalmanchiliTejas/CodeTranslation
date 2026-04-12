import numpy as np

H, W = (int(i) for i in input().split())

a = []
array = np.zeros((H,W))
for i in range(H):
    tmp = [i for i in input().split()]
    for j in range(W):
        if(tmp[0][j]=="."):
            array[i,j]=0
        else:
            array[i,j]=1

#---------------
survive_h = []
survive_w = []

for i in range(H):
    if(np.sum(array[i])!=0):
        survive_h.append(i)

for i in range(W):
    if(np.sum(array[:, i])!=0):
        survive_w.append(i)

deleted_array = array[survive_h][:,survive_w]

for i in range(len(deleted_array)):
    s=""
    for j in range(len(deleted_array[0])):
        if(deleted_array[i][j]==1):
            s += "#"
        else:
            s += "."
    print(s)
