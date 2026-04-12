N, X = map(int, input().split())
h = [1]
p = [1]
for i in range(N):
    h.append(h[i]*2+3)
    p.append(p[i]*2+1)
def f(N,X):
    if X == 1:
        if N == 0:
            return 1
        return 0
    elif 1 < X and X <= 1 + h[N-1]:
        return f(N-1,X-1)
    elif X == 2 + h[N-1]:
        return p[N-1] + 1
    elif 2 + h[N-1] < X and X <= 2 + 2 * h[N-1]:
        return p[N-1] + 1 + f(N-1,X-2-h[N-1])
    elif X == 3 + 2 * h[N-1]:
        return p[N]
print(f(N,X))