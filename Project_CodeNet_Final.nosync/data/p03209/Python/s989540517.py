N, X = map(int, input().split())
B = [1]
P = [1]

for i in range(N):
    B.append(2 * B[i] + 3)
    P.append(2 * P[i] + 1)

    
def f(N, X):
    if N == 0:
        if X <= 0:
            return 0
        else:
            return 1
    elif X <= 1 + B[N - 1]:
        return f(N - 1, X - 1)
    else:
        return P[N - 1] + 1 + f(N - 1, X - 2 - B[N - 1])

print(f(N, X))