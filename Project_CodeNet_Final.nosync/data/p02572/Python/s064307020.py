n = int(input())
a = list(map(int, input().split()))
t = [0]
mod = 10**9 + 7
for i in range(n):
    t.append((t[-1] + a[i])% mod)

ans = 0
for i in range(n-1):
    ans += a[i] * (t[-1] - t[i+1])%mod
    ans %= mod

print(ans)

