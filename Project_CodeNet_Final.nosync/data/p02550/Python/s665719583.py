N, X, M = map(int, input().split())

G = {X: 0}
a = X
while True:
    na = pow(a, 2, M)
    if na in G:
        s = G[na]
        sa = na
        g = G[a]
        break
    else:
        G[na] = G[a] + 1
        a = na

if N <= s:
    ans1 = 0
    a = X
    for i in range(N):
        ans1 += a
        a = pow(a, 2, M)
    print(ans1)
else:
    ans1 = 0
    a = X
    for i in range(s):
        ans1 += a
        a = pow(a, 2, M)

    L = g - s + 1
    S = [0] * (L + 1)
    a = sa
    for i in range(L):
        S[i + 1] = S[i] + a
        a = pow(a, 2, M)

    rest = N - s
    x, y = divmod(rest, L)
    ans2 = S[-1] * x + S[y]

    print(ans1 + ans2)
