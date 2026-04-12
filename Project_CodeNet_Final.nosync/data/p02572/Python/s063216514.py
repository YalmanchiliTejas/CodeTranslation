N = int(input())
A = list(map(int, input().split()))

ans = 0
mod = int(1e9 + 7)
s = sum(A) % mod

for a in A:
    s -= a
    ans += (a * s) % mod
    ans %= mod

print(int(ans))