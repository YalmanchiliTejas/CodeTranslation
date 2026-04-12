n=int(input())
mod=int(1e9)+7
l=[int(x) for x in input().split()]
sum1=0
sum2=0
for i in range(n):
    sum2=(sum2%mod+l[i]%mod)%mod
for i in range(n-1):
    sum2=sum2-l[i]
    x=(sum2%mod*(l[i]%mod))%mod
    sum1=(sum1%mod+(x%mod))%mod
print(sum1)
