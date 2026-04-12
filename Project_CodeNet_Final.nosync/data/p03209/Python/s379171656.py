N, X = [int(_) for _ in input().split()]

A = [1]
for i in range(N):
    A.append(A[-1] * 2 + 3)
P = [1]
for i in range(N):
    P.append(2 * P[-1] + 1)


def f(n, x):
    if n <= 0 and x == 1: return 1
    if x == 1: return 0
    if x <= A[n - 1] + 1:
        return f(n - 1, x - 1)
    if A[n - 1] + 2 == x:
        return P[n - 1] + 1
    if 2 * A[n - 1] + 3 > x:
        return P[n - 1] + 1 + f(n - 1, x - A[n - 1] - 2)
    else:
        return 2 * P[n - 1] + 1


print(f(N, X))
