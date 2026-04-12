N, X = map(int, input().split())

B = [0] * 55
P = [0] * 55
P[0] = 1
for i in range(N):
    B[i + 1] = B[i] * 2 + 2
    P[i + 1] = P[i] * 2 + 1

def len(i):
    return B[i] + P[i]

def f(l, x):
    if l == 0:
        return 1
    if x == 1:
        return 0
    if x <= len(l - 1) + 1:
        return f(l - 1, x - 1)
    if x == len(l - 1) + 2:
        return P[l - 1] + 1
    if x <= len(l - 1) * 2 + 2:
        return P[l - 1] + f(l - 1, x - (len(l - 1) + 2)) + 1
    return P[l]

print(f(N, X))
