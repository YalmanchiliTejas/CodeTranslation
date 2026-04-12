def modinv(val, mod):
    b, u, v = mod, 1, 0
    while b:
        t = val // b
        val = val - t * b
        val, b = b, val
        u = u - t * v
        u, v = v, u
    u = u % mod
    return u


n = int(input())
a = list(map(int, input().split()))
mod = 10 ** 9 + 7
total = 0
for item in a:
    total = (total + item) % mod

total = (total * total) % mod

for item in a:
    total = (total - (item * item)) % mod

print(total * modinv(2, mod) % mod)
