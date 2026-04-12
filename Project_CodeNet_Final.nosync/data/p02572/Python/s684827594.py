n = int(input())
A = map(int,input().split())

mod = 1000000007

ans = 0
tmp1, tmp2 = 0, 0

for m in A:
  tmp1 = (tmp1+m) %mod
  tmp2 = (tmp2+m*m%mod)%mod
  
ans = ((tmp1*tmp1)%mod-tmp2)%mod

if ans%2 ==0:
  ans = ans/2
else:
  ans =(ans+mod)/2

print(int(ans))