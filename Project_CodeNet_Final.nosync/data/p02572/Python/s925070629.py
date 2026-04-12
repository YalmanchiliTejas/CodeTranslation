n=int(input())
vec=list(map(int,input().split()))
mod=10**9+7
wa=[i for i in vec]
for i in range(n-1):
  wa[i+1]+=wa[i]
ans=0
for i in range(n):
  ans += vec[i]*((wa[n-1]-wa[i])%mod)%mod
  ans %= mod
print(ans)