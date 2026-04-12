N, X = map(int, input().split())

p = [0]*(N+1)
a = [0]*(N+1)
p[0] = 1
a[0] = 1
for i in range(1, N+1):
    p[i] = 2 * p[i-1] + 1
    a[i] = 2 * a[i-1] + 3

def f(N, X):
    i = N
    if N == 0:
        if X <= 0:
            return 0
        if X >= 1:
            return 1
    if X == 1:
        return 0
    elif X > 1 and X <= 1 + a[i-1]:
        return f(N-1, X-1)
    elif X == 2 + a[i-1]:
        return p[i-1] + 1
    elif X > 2 + a[i-1] and X <= 2 + 2*a[i-1]:
        return p[i-1] + 1 + f(N-1, X-2-a[i-1])
    else:
        return 2*p[i-1] + 1

print(f(N, X))