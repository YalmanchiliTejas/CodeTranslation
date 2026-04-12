N = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
S = sum(a) % mod
ans = 0

for x in a:
    S -= x
    S %= mod
    ans += S * x
    ans %= mod

print(ans)