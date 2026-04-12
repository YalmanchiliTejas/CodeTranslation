import numpy as np

H, W = map(int, input().split())

a = []
for i in range(H):
    a.append(list(map(int, input().replace("#","1").replace(".","0"))))

a = np.array(a)

d1 = (np.sum(a, axis=1) == 0)
d2 = (np.sum(a, axis=0) == 0)

ret = []

for i in range(H):
    tmp = ""
    if d1[i]:
        continue
    for j in range(W):
        if d2[j]:
            continue
        tmp = tmp + str(a[i,j])
    ret.append(tmp.replace("1","#").replace("0","."))
        

print(*ret,sep="\n")
        
