n = int(input())
a = list(map(int,input().split()))

MOD=10**9+7

sum1=0
for i in range(n):
    sum1+=a[i]
    sum1%=MOD

sum1*=sum1
sum1%=MOD
sum2=0
for i in range(n):
    sum2+=pow(a[i],2,MOD)
    sum2%=MOD

t = sum1-sum2
if t<0:
    t+=MOD

print((t)*pow(2,MOD-2,MOD)%MOD)
