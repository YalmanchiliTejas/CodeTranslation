n=int(input())
a=list(map(int,input().split()))
mod=1000000007
sum_a=sum(a)

ans=0
for i in range(n):
    temp=(sum_a-a[i])*a[i]

    ans+=temp
print((ans//2)%mod)
