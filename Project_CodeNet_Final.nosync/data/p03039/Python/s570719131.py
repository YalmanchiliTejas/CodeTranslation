def powerf(a, b, md):
    """a^b mod md"""
    if b == 0:
        return 1

    if b % 2 == 0:
        pf2 = powerf(a, b // 2, md)
        return pf2**2 % md
    else:
        return (a * powerf(a, b-1, md)) % md


def comb(n, k, md):
    """nCk mod md"""
    from math import factorial

    if n < 0 or k < 0 or n < k:
        return 0
    if n == 0 and k == 0:
        return 1

    a = factorial(n) % md
    b = factorial(k) % md
    c = factorial(n-k) % md
    return a * powerf(b, md-2, md) * powerf(c, md-2, md) % md


M = 10**9 + 7

n, m, k = list(map(int, input().split()))
ans = 0
for dx in range(1, m):
    ans += dx * (m - dx) * n**2

for dy in range(1, n):
    ans += dy * (n - dy) * m**2

print(ans * comb(n*m-2, k-2, M) % M)