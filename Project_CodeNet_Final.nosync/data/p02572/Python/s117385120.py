n = int(input())
a = list(map(int, input().split()))
mod = 10 ** 9 + 7

sm = 0
ans = 0
for e in a:
    ans += e * sm
    ans %= mod
    sm += e
    sm %= mod

print(ans)
