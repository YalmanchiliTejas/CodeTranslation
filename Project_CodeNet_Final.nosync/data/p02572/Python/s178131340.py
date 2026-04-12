n = int(input())
a = list(map(int, input().split()))

mod = 10**9+7
s = 0

for i in a:
    s += i
    s %= mod

s = (s * s) % mod
for i in a:
    s -= i*i
    s %= mod

s = s*(5*(10**8)+4)

print(s%mod)