N, S = map(int, input().split())
mod = 998244353
A = list(map(int, input().split()))
L = [0 for _ in range(S+1)]
p = 0
F = {0}
for i in range(N):
    L[0] += 1
    X = [[j, L[j]] for j in F]
    for j in X:
        if j[0] + A[i] <= S:
            L[j[0]+A[i]] += j[1]
            L[j[0]+A[i]] %= mod
            F.add(j[0]+A[i])
    p += L[S]
    p %= mod

print(p)