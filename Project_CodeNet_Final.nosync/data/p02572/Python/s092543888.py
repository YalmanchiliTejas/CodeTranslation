from sys import stdin,stdout
def INPUT():return list(int(i) for i in stdin.readline().split())
def inp():return stdin.readline()
def out(x):return stdout.write(x)
import math
import random
J=int(1e9)+7

###############################################################################\n=17
n=int(input())
A=INPUT()
sum=0
for i in range(n):
    sum+=A[i]
sum=sum*sum

s=0
for i in range(n):
    s+=A[i]**2

ans=(sum-s)//2
ans%=J
print(ans)
