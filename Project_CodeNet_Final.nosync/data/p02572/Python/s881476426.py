n = int(input())
a = list(map(int, input().split()))

mod = 10 ** 9 + 7

s = 0
ans = 0

for i in a:
    ans += s * i
    ans %= mod
    s += i
    s %= mod

print(ans)