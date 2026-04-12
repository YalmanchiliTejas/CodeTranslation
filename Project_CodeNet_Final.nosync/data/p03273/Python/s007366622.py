h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

aa = []
for i in range(h):
    if a[i] != ["."]*w:
         aa.append(a[i])
        

import numpy as np

aaa = np.array(aa)

aaaa=[]
for i in range(aaa.T.shape[0]):
    if "".join(aaa.T[i]) != "."*aaa.T.shape[1]:
         aaaa.append(aaa.T[i])
            
tm = np.array(aaaa).T

for i in range(tm.shape[0]):
    print("".join(tm[i]))