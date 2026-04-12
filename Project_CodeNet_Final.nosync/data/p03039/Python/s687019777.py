import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

import numpy as np

# 2点間の距離の平均を求めればよい

MOD = 10**9 + 7

N,M,K = map(int,read().split())

def cumprod(arr,MOD):
    L = len(arr); Lsq = int(L**.5+1)
    arr = np.resize(arr,Lsq**2).reshape(Lsq,Lsq)
    for n in range(1,Lsq):
        arr[:,n] *= arr[:,n-1]; arr[:,n] %= MOD
    for n in range(1,Lsq):
        arr[n] *= arr[n-1,-1]; arr[n] %= MOD
    return arr.ravel()[:L]

def make_fact(U,MOD):
    x = np.arange(U,dtype=np.int64); x[0] = 1
    fact = cumprod(x,MOD)
    x = np.arange(U,0,-1,dtype=np.int64); x[0] = pow(int(fact[-1]),MOD-2,MOD)
    fact_inv = cumprod(x,MOD)[::-1]
    return fact,fact_inv

U = 10**6
fact, fact_inv = make_fact(U,MOD)

coef = fact[N*M-2] * fact_inv[K-2] % MOD * fact_inv[N*M-K] % MOD

x = (N-1)*N*(N+1)*M*M//6
y = (M-1)*M*(M+1)*N*N//6
answer = coef * ((x+y) % MOD) % MOD
print(answer)