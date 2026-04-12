#d=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
#import numpy as np
import math
#n=int(input())
#li=input().split()
#S=input()
#import fractions
#lis=list(map(int,input().split()))

n=int(input())
s=input()
k=int(input())

l=s[k-1]

ans=""
for i in range(n):
    if s[i]!=l:
        ans+="*"
    else:
        ans+=l


print(ans)
