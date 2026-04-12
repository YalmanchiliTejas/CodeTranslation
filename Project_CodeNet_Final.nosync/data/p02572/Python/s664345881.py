from sys import stdin,stdout
from collections import defaultdict
import math
from bisect import bisect
#input=stdin.readline
#def print(x):stdout.write(str(x)+'\n')
n=int(input())
arr=list(map(int,input().split()))
result = 0
su=sum(arr)
s=[]
s1=0
for i in range(n):
    s1+=arr[i]
    s.append(su-s1)

for i in range(0, n): 
    result+=(arr[i]*s[i])
print((result)%(10**9+7))