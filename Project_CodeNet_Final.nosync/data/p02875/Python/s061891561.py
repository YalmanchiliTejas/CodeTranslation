MOD = 998244353

N = int(input())

ans = pow(3, N, MOD)

def getInvs(n, MOD):
    invs = [1] * (n+1)
    for x in range(2, n+1):
        invs[x] = (-(MOD//x) * invs[MOD%x]) % MOD
    return invs

def getCombNs(n, invs, MOD):
    combNs = [1] * (n//2+1)
    for x in range(1, n//2+1):
        combNs[x] = (combNs[x-1] * (n-x+1) * invs[x]) % MOD
    return combNs + combNs[:(n+1)//2][::-1]

invs = getInvs(N, MOD)
combNs = getCombNs(N, invs, MOD)

pow2 = 1
for i in range((N-1)//2+1):
    num = combNs[i] * pow2
    ans -= num*2 % MOD
    ans %= MOD
    pow2 *= 2
    pow2 %= MOD

print(ans)
