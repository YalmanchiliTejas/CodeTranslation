import numpy as np
n,m = map(int,input().split())
a = list()
for i in range(n):
    a.append(list(input()))
line = np.array(a)
delete_r,delete_g=list(),list()
for i in range(n):
    if "#" not in line[i]:
        delete_g.append(i)
line = np.delete(line,delete_g,0)
for i in range(m):
    if "#" not in line[:,i]:
        delete_r.append(i)
line = np.delete(line,delete_r,1)
for i in line:
    for j in i:
        print(j,end="")
    print()
