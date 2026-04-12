N, S = map(int, input().split())
A = [int(a) for a in input().split()]
X = [0] * 3001
pre = 0
ans = 0
P = 998244353
for i, a in enumerate(A):
    for j in range(S, a, -1):
        X[j] = (X[j] + X[j-a]) % P
    X[a] = (X[a] + i + 1) % P
    ans = (ans + (X[S] - pre) * (N - i)) % P
    pre = X[S]
print(ans)