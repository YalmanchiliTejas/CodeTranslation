import math
def ip():return int(input())
def inp():return map(int,input().split())
def inpstr():return map(str,input().split())
def linp():return list(map(int,input().split()))
def linpstr():return list(map(str,input().split()))

n=ip()
h=linp()
ans=1
for i in range (1,n):
    f=True
    for j in range(i):
        if h[i]<h[j]:f=False
    if f==True:ans+=1
print(ans)