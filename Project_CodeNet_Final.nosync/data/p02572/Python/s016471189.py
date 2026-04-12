n=int(input())
a=list(map(int,input().split()))
MOD=10**9+7
tot=(sum(a))%MOD
ans=0
for i in range(n):
  ans=(ans+a[i]*(tot-a[i]))%MOD
ans=(ans*pow(2,MOD-2,MOD))%MOD
print(ans)