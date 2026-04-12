#間違い
inf=float("inf")
from heapq import heappop,heappush 
n=int(input())
a=[int(input()) for _ in range(n)]
dp=[-1]*(n)
dp[0]=a[0]
for i in range(1,n):
    m=0
    M=n-1
    while M-m>1:
        if dp[(M+m)//2]<a[i]:
            M=(M+m)//2
        else:
            m=(M+m)//2
    if dp[m]>=a[i]:
        dp[M]=a[i]
    else:
        dp[m]=a[i]
count=0
for i in range(n):
    if dp[i]!=-1:
        count+=1
    else:
        break
print(count)