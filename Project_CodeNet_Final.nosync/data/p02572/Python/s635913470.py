n=int(input())
arr=list(map(int,input().split()))
suma=sum(arr)
suff=[suma]*n
mod=1000000007
suff[n-1]=arr[n-1]
for i in range(n-2,-1,-1):
    suff[i]=suff[i+1]+arr[i]
ans=0
for i in range(1,n):
    ans+=arr[i-1]*suff[i]
    ans%=mod
print(ans)