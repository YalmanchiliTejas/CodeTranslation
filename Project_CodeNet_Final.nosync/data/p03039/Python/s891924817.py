n, m, k = list(map(int, input().split()))
MOD = 10 ** 9 + 7

t = 0
pre = [0]
for i in range(1, max(n, m) + 1):
    t += i
    pre.append(t)


def calc_base(n, m, pre):
    base = 0
    for i in range(n // 2):
        base = base + (pre[i] + pre[n - i - 1]) * 2 % MOD
    if n % 2 == 1:
        i = n // 2
        base = (base + pre[i] * 2) % MOD
    return base * m * m % MOD


bi = calc_base(n, m, pre)
bj = calc_base(m, n, pre)


def prepare(n, MOD):
    f = 1
    for m in range(1, n + 1):
        f *= m
        f %= MOD
    fn = f

    inv = pow(f, MOD - 2, MOD)
    invs = [1] * (n + 1)
    invs[n] = inv
    for m in range(n, 1, -1):
        inv *= m
        inv %= MOD
        invs[m - 1] = inv

    return fn, invs


nm = n * m - 2
f, inv = prepare(nm, MOD)
print((bi + bj) * f * inv[k - 2] % MOD * inv[nm - k + 2] * inv[2] % MOD)
