MOD=10**9+7
N=int(input())
ls=[int(s)%MOD for s in input().split()]
s=0
d=0
for x in ls:
  s=(s+x)%MOD
  d=(d+x*x)%MOD

ans=((s*s-d)*500000004)%MOD
print(ans)