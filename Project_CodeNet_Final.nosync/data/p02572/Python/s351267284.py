n=int(input())
A=list(map(int,input().split()))
limit=10**9+7
A.reverse()
ans=0
count=0
for i in range(n-1):
    count+=A[i]
    ans=ans+(count*A[i+1])
print(ans%limit)