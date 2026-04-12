n=int(input())
a=list(map(int,input().split()))
accum=[0]
for i in range(n):
    accum.append(accum[i]+a[i])
ans=0
for i in range(0,n-1):
    ans+=a[i]*(accum[n]-accum[i+1])
    ans%=10**9+7
print(ans)