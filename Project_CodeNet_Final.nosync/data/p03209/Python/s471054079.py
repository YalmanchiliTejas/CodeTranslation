N, X = map(int, input().split())

bur = [1]
pati = [1]
for i in range(N):
    bur.append(bur[i] * 2 + 3)
    pati.append(pati[i] * 2 + 1)


def f(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= 1 + bur[N - 1]:
        return f(N - 1, X - 1)
    else:
        return pati[N - 1] + 1 + f(N - 1, X - 2 - bur[N - 1])


print(f(N, X))
