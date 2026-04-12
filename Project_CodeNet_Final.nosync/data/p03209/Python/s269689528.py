N, X = map(int, input().split())
L, P = [1], [1]
for _ in range(N - 1):
    L.append(L[-1] * 2 + 3)
    P.append(P[-1] * 2 + 1)


def ans(N, X):
    if N == 0:
        return 1 if X >= 1 else 0
    elif X <= 1:
        return 0
    elif X <= L[N - 1] + 1:
        return ans(N - 1, X - 1)
    else:
        return P[N - 1] + 1 + ans(N - 1, X - (L[N - 1] + 2))


print(ans(N, X))
