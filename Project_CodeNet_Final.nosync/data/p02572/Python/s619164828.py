n = int(input())
A = list(map(int, input().split()))
mod = 10**9+7
s = 0
ans = 0
for a in A:
    ans += s*a
    ans %= mod
    s += a
    s %= mod
print(ans)
