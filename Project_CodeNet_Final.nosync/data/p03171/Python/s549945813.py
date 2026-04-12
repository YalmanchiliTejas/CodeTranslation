# coding: utf-8
# Your code here!


n = int(input())
aa = [int(i) for i in input().split()]

INF = 10**13
#from itertools import accumulate, product, permutations, combinations, groupby
#acc = accumulate([0]+aa)

#dp[x][y] = (bの位置x,aの」位置y)
dp= [[0]*(i+1) for i in range(n+1)]
#dp[n][0]=0
"""
for b in range(n,-1,-1):
    for a in range(b+1):
#        print(b,a)
#        print(dp)
        c=(n-a-b)%2
        if c:
            if b<n and a>0:
                dp[b][a] = max(dp[b+1][a] + aa[b], dp[b][a-1]+aa[a-1])
            elif b<n:
                dp[b][a] = dp[b+1][a] + aa[b]
            elif a>0:
                dp[b][a] = dp[b][a-1]+aa[a-1]
        else:
            if b<n and a>0:
                dp[b][a] = min(dp[b+1][a] - aa[b], dp[b][a-1]-aa[a-1])
            elif b<n:
                dp[b][a] = dp[b+1][a] - aa[b]
            elif a>0:
                dp[b][a] = dp[b][a-1] - aa[a-1]

print(dp)
for b in range(1,n+1):
    for a in range(b-1,-1,-1):
#        print(b,a)
        c=(n-a-b)%2
        if c:
            dp[b][a] = max(dp[b-1][a], dp[b][a+1])
        else:
            dp[b][a] = min(dp[b-1][a], dp[b][a+1])
"""

for b in range(1,n+1):
    for a in range(b-1,-1,-1):
#        print(b,a)
        c=(n-a-b+1)%2
        if c:
            dp[b][a] = max(dp[b-1][a]+aa[b-1], dp[b][a+1]+aa[a])
        else:
            dp[b][a] = min(dp[b-1][a]-aa[b-1], dp[b][a+1]-aa[a])

#print(dp)
print(dp[n][0])






