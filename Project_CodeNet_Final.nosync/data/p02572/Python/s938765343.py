n=int(input())
a=list(map(int,input().split()))
sum=0
mod=10**9+7
for i in range(n):
    sum+=a[i]
sum=sum**2
for i in range(n):
    sum-=a[i]**2
sum=(sum//2)%mod
print(sum)

