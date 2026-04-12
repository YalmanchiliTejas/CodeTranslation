import numpy as np
#input
#N = 5
#H = [9,5,6,8,4]
N = int(input())
H = list(map(int,input().split()))
tmp = 0
for i in range(N):
    if H[i] == max(H[0:i+1]):
        tmp += 1

print(tmp)
