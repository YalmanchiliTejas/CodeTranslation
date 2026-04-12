N = int(input())
A = list(map(int, input().split()))
mod = 10 ** 9 + 7

sums = 0
for a in A:
    sums += a
    sums %= mod

ans = 0

for a in A:
    sums = (sums - a) % mod
    ansi = (sums * a) % mod
    ans += ansi
    ans %= mod

print(ans)
