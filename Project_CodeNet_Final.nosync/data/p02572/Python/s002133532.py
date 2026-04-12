import numpy as np
n = int(input())
a = np.array(list(map(int, input().split())))
s=[0]*(n-1)
tmp=0
for i in range(n-1):
    tmp=(tmp+a[(i+1)*-1])%(10**9+7)
    s[(i+1)*-1]=tmp
    
print(int((s*a[:-1]%(10**9+7)).sum()%(10**9+7)))