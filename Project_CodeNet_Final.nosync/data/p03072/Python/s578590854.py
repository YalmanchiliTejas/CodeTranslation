import sys
import os


N=int(input())
H= list(map(int,input().split()))
Hmax=H[0]
count=1
for i in range(N-1):
    if H[i+1]>=Hmax:
        count+=1
    Hmax=max(Hmax,H[i+1])

print(count)