def xgcd(a, b):
    x0, y0, x1, y1 = 1, 0, 0, 1
    while b != 0:
        q, a, b = a // b, b, a % b
        x0, x1 = x1, x0 - q * x1
        y0, y1 = y1, y0 - q * y1
    return a, x0, y0

def modinv(a, m):
    g, x, y = xgcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

MOD = 998244353
N = int(input())
#N = 10 ** 7
n = N // 2
ansx = 1
tmp2 = 1
tmpc = 1
for i in range(1, n):
    tmp2 = (tmp2 * 2)%MOD
    tmpc = (tmpc * (2 * n - i + 1) * modinv(i, MOD)) % MOD
    ansx = (ansx + tmp2 * tmpc)%MOD

ans = pow(3, N, MOD)
ans = (ans + 2 * MOD - ansx * 2)%MOD
print(ans)