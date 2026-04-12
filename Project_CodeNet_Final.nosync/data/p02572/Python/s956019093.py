n = int(input())
l = list(map(int,input().split()))
mod = 10**9+7

s = sum(l)%mod
ans = 0

for i in range(n):
    s = (s-l[i])%mod
    ans += l[i]*s%mod
    
print(ans%mod)