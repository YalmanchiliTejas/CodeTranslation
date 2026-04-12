def inverse(a, mod):
    a %= mod # 除数が正なら正になる
    p = mod
    x, y = 0, 1
    while a > 0:
        n = p // a
        p, a = a, p % a, 
        x, y = y, x - n * y
    return x % mod # 除数が正なら正になる
mod = 10 ** 9 + 7
n = int(input())
a = list(map(int, input().split()))
s = sum(a)

ans = 0
for x in a:
    ans = (ans + x * (s - x)) % mod
print (ans * inverse(2, mod) % mod)

