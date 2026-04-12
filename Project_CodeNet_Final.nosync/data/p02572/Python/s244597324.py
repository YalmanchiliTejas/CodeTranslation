from sys import stdin,stdout
from itertools import accumulate
n=int(stdin.readline());M=10**9+7
a=list(map(int,stdin.readline().split()))
ps=list(accumulate(a[::-1]))[::-1]
ans=0
for i in range(n-1):
    ans=(ans+a[i]*(ps[i+1]))%M
print(ans%M)