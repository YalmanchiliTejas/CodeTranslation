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


n = int(input())
MOD = 998244353
fn, invs = prepare(n, MOD)
ans = pow(3, n, MOD)
impossible = 0
mul = 2
for i in range(n // 2):
    tmp = fn * invs[i] * invs[n - i] % MOD * mul
    impossible = (impossible + tmp) % MOD
    mul = mul * 2 % MOD
print((ans - impossible) % MOD)
