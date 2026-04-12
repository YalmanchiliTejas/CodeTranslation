import numpy as np

H,W=map(int,input().split())
a=np.zeros((H,W))
for i in range(H):
    tmp = input()
    for j in range(W):
        if tmp[j] == "#":
            a[i][j]=1

tmp=[]
for i in range(H):
    if np.sum(a[i])==0:
        tmp.append(i)
a = np.delete(a,tmp,0)

h=len(tmp)

a = a.T

tmp=[]
for i in range(W):
    if np.sum(a[i])==0:
        tmp.append(i)
a = np.delete(a,tmp,0)
               
a = a.T

w = len(tmp)

ans = list(a)

for i in range(H-h):
    tmp=a[i]
    for j in range(W-w):
        if tmp[j] == 1:
            print("#", end="")
        else:
            print(".", end="")
    print()
