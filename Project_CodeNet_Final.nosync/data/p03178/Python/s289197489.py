MOD = 10**9 + 7
K = input()
N = len(K)
D = int(input())

S = [[0, 0] for i in range(D)]
S[0][0] = 1
for i in range(N):
    c = int(K[i])
    T = [[0, 0] for i in range(D)]
    for d in range(D):
        w0, w1 = S[d]
        w0 %= MOD
        w = S[d][0] % MOD
        for v in range(c):
            T[(d+v)%D][1] += w0
        T[(d+c)%D][0] += w0

        w1 %= MOD
        for v in range(10):
            T[(d+v)%D][1] += w1
    S = T
print((sum(S[0])-1) % MOD)