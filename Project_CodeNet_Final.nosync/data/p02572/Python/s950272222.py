N = int(input())
A = list(map(int, input().split()))
x, y = 0, 0
mod = 10**9+7
for a in A:
    x = (x + a) % mod
    y = (y + a * a) % mod
print((x * x % mod - y) * pow(2, mod - 2, mod) % mod)
