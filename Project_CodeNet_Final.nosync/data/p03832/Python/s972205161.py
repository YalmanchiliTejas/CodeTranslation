N, A, B, C, D = map(int, input().split())
mod = 7 + 10 ** 9

fact = [1] * (N+1)
frev = [1] * (N+1)
for i in range(1, N+1):
    temp = fact[i] = (fact[i-1] * i) % mod
    frev[i] = pow(temp, mod-2, mod)

def P(n, r):
    return (fact[n] * frev[n-r]) % mod

DP = [[0 for j in range(N+1)] for i in range(N+1)]
for i in range(N+1): DP[i][0] = 1
for i in range(A, B+1):
    revi = frev[i]
    for j in range(1, N+1):
       dpij = 0 + DP[i-1][j]
       for k in range(C, D + 1):
           if j - i * k < 0: break
           temp = (P(N-j+i*k, i*k) * pow(revi, k, mod) * frev[k]) % mod
           dpij += (temp * DP[i-1][j-i*k]) % mod
       DP[i][j] = dpij % mod

print(DP[B][N])
