n = int(input())
a = list(map(int, input().split()))
mod = pow(10, 9) + 7
s = sum(a) % mod
ans = s * s % mod
for i in a:
    ans -= i * i
    ans %= mod
ans = ans * pow(2, mod - 2, mod) % mod
print(ans)