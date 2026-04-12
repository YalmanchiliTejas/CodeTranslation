import numpy as np

N = int(input())

H = [int(i) for i in input().split()]

count =0

for i in range(N):
    if i ==0:
        count+=1
        H_max_so_far = H[i]
    else:
        if H[i] >= H_max_so_far:
            count+=1
            H_max_so_far = H[i]
            
print(count)