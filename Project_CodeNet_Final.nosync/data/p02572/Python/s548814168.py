n, *aa = map(int, open(0).read().split())
MOD = 10**9+7
print(
    (
        (sum(aa)%MOD) ** 2 % MOD
        - sum(a**2%MOD for a in aa) % MOD
    )
    * pow(2, MOD-2, MOD)
    % MOD
)