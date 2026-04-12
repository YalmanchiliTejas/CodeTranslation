ma = lambda :map(int,input().split())
lma = lambda :list(map(int,input().split()))
tma = lambda :tuple(map(int,input().split()))
ni = lambda:int(input())
yn = lambda fl:print("Yes") if fl else print("No")
ips = lambda:input().split()
import collections
import math
import itertools
import heapq as hq
n,x,m = ma()
idx = [[] for i in range(m)]
tmp=[]
ans = 0
l=0
r=0
for i in range(m+3):
    x = x%m
    tmp.append(x)
    #print(tmp)
    if idx[x]==[]:
        idx[x].append(i)
    else:
        l = idx[x][0]
        r=i
        break
    ans+=x
    x*=x
    if i==n-1:
        print(ans)
        exit()
#print(l,r)
s =sum(tmp[l:r])
d = r-l
p,q = divmod(n-r,d)
ans+=s*p
for i in range(l,l+q):
    ans+=tmp[i]
print(ans)
