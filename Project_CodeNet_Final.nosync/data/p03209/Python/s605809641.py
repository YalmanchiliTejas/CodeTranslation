n, x = map(int, input().split())

PB, P = [1] * (n + 1), [1] * (n + 1)
for i in range(1, n + 1):
    PB[i] = 2 * PB[i - 1] + 3; P[i] = 2 * P[i - 1] + 1

def f(n, x):
    c = PB[n] // 2 + 1
    if x == 0:
        return 0
    if x == PB[n]:
        return P[n]
    if x < c:
        return f(n - 1, x - 1)
    else:
        return P[n - 1] + 1 + f(n - 1, x - c)

print(f(n, x))
