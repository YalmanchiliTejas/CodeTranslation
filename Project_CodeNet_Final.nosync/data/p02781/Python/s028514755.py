S = input()
N = len(S)
K = int(input())

MOD = 10 ** 9 + 7
fact = [1, 1]
factinv = [1, 1]
inv = [0, 1]

# 必要なだけforを回す
for i in range(2, 10 ** 6):
    fact.append((fact[-1] * i) % MOD)
    inv.append((-inv[MOD % i] * (MOD // i)) % MOD)
    factinv.append((factinv[-1] * inv[-1]) % MOD)

# nCr n個から重複を許さずr個の組み合わせを選ぶ
def cmb(n, r):
    if (r < 0) or (n < r):
        return 0
    r = min(r, n - r)
    return fact[n] * factinv[r] * factinv[n-r] % MOD

def rec(i, k, isSmaller):
    if i == N:
        if k == 0:
            return 1
        else:
            return 0
    
    if k == 0:
        return 1
    
    if isSmaller:
        return cmb(N-i, k) * pow(9, k)
    else:
        if S[i] == '0':
            return rec(i+1, k, False)
        else:
            zero = rec(i+1, k, True)
            between = rec(i+1, k-1, True) * (int(S[i]) - 1)
            same = rec(i+1, k-1, False)
            return zero + between + same

print(rec(0, K, False))
