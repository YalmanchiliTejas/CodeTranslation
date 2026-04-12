N, X = map(int, input().split())
L = [0] * (N + 1)
L[0] = 1
for i in range(1, N + 1):
    L[i] = 2 * L[i - 1] + 3

P = [0] * (N + 1)
P[0] = 1
for i in range(1, N + 1):
    P[i] = 2 * P[i - 1] + 1


def calc(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= 1 + L[N - 1]:
        return calc(N - 1, X - 1)
    else:
        return P[N - 1] + 1 + calc(N - 1, X - 2 - L[N - 1])


print(calc(N, X))
