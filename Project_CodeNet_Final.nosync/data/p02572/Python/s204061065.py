n = int(input())
a = list(map(int, input().split()))
accu = [0]
mod = 10**9+7
for i in range(n):
    accu.append((accu[-1]+a[i])%mod)
ans = 0
for i in range(n-1):
    ans += (a[i]*(accu[-1]-accu[i+1]))%mod
    ans %= mod
print(ans)