mod = 10 ** 9 + 7

n = int(input())
a = list(map(int, input().split()))

s = sum(a) 

ans = 0

for i in a:
    s -= i
    s %= mod
    ans += i * s
    ans %= mod

print(ans)