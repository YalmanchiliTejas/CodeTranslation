#d=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
#import numpy as np
#import math
#n=int(input())
#li=input().split()
#S=input()

n=int(input())
lis=list(map(int,input().split()))
ans=1
for i in range(1,n):
    a=0
    for j in range(i):
        if lis[i]>=lis[j]:
            a+=1
        else:
            break
    if a==i:
        ans+=1

print(ans)
