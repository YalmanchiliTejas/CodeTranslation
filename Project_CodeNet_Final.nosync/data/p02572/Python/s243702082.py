n = int(input())
a = list(map(int, input().split()))

mod = 1000000007
s = sum(a) % mod
ans = 0

for i in a:
    s -= i
    ans += s * i
    ans %= mod

print(ans)
