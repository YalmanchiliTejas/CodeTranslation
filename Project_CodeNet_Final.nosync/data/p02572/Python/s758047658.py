n=int(input())
a=list(map(int,input().split()))
mod = 10**9+7

ans = 0
aa = 0
for i in range(n-1):
    aa += a.pop()
    # print(a,aa)
    ans +=  (aa * a[-1]) % mod
    ans %= mod

print(ans%mod)