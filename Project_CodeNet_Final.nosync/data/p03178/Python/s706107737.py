

MOD = 1000000007

def F(k, s):
    return dp[k][s]

def solve(n):
    resp = 0
    n = map(int, str(n))
    pref = 0
    for i in range(len(n)):
        for d in range(n[i]):
            resp += F(len(n) - i - 1, (pref - d) % D)
            resp %= MOD
        pref -= n[i]
        pref %= D
    return resp


K = raw_input()
D = input()

# dp[i][j] = cant de numeros de i digitos con suma % d = j
dp = [[0] * D for _ in range(len(K) + 1)]
dp[0][0] = 1
for i in range(1, len(K) + 1):
    for j in range(D):
        for d in range(10):
            dp[i][j] += dp[i - 1][(j - d) % D]
            dp[i][j] %= MOD

resp = solve(K) - 1
if sum(map(int, str(K))) % D == 0:
    resp += 1
print(resp % MOD)
