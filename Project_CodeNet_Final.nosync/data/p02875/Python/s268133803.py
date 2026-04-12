#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

MOD = 998244353
MAX_N = 10**7 

fac = [1] + [0] * MAX_N
fac_inv = [1] + [0] * MAX_N
mod_pow2_n = [1] + [0] * MAX_N
for i in range(1, MAX_N+1):
    fac[i] = fac[i-1] * i % MOD
    mod_pow2_n[i] = mod_pow2_n[i-1] * 2 % MOD

fac_inv[MAX_N] = pow(fac[MAX_N], MOD-2, MOD)
for i in range(MAX_N, 1, -1):
    fac_inv[i-1] = fac_inv[i] * i % MOD

def mod_nCr(n, r):
    if n < r or n < 0 or r < 0:
        return 0
    tmp = fac_inv[n-r] * fac_inv[r] % MOD
    return tmp * fac[n] % MOD 
    
n = int(input())
ans = 0
for i in range(n//2+1, n+1):
    ans += mod_nCr(n, i) * mod_pow2_n[n-i]
    ans %= MOD
print((pow(3, n, MOD) - ans * 2 + MOD)%MOD)