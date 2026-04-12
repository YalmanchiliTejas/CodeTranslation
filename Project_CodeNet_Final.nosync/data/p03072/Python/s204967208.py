import numpy as np
N = int(input())
A = list(map(int,input().split()))
B = np.array(A)
count = 0
for i in range(1,N):
    if max(B[:i])<=B[i]:
        count +=1
print(count+1)