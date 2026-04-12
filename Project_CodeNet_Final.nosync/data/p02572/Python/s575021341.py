n = int(input())
a = list(map(int, input().split()))

mod = 7 + 10 ** 9
s = sum(a) % mod
ans = 0

for i in a:
    s -= i
    ans += s * i
    ans %= mod
print(ans)
