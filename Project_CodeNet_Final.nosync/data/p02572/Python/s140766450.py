n = int(input())
data = list(map(int, input().split()))
mod = 10**9 + 7

total = sum(data)

ans = 0
for a in data:
    total -= a
    ans += a*(total)
    ans %= mod

print(ans)