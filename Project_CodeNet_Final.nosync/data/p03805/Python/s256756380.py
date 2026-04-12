import itertools
import numpy as np
n,m = map(int,input().split())
a = [0] * m
b = [0] * m
ans = 0
for i in range(m):
    a[i], b[i] = map(int, input().split())
    
gudge = np.zeros((n, n), dtype = np.int64)
for i in range(m):
    gudge[a[i]-1][b[i]-1] = 1
    gudge[b[i]-1][a[i]-1] = 1

retsu = [i+2 for i in range(n-1)]
p = itertools.permutations(retsu, n-1)

for v in p:
    path = [1]+list(v)
    flag = 1
    for i in range(n-1):
        if gudge[path[i]-1][path[i+1]-1] != 1:
            flag = 0
            break
            
    ans += flag
    
print(ans)