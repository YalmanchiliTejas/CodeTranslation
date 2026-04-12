n=int(input())
a=list(map(int,input().split()))
mod=1000000007
summ=sum(a)%mod
tot=0
for i in range(n):
    summ-=a[i]
    tot+=(a[i]*summ)%mod
print(tot%mod)