N, X = map(int, input().split())
a = [1]
for i in range(N):
    a.append(2*a[i] + 3)
p = [1]
for i in range(N):
    p.append(2*p[i] + 1)
def f(N, X):
    if N == 0:
        if X == 0:
            return 0
        else:
            return 1
    elif N >= 1:
        if 0 <= X <= 1:
            return 0
        elif 1 < X <= 1 + a[N-1]:
            return f(N-1, X-1)
        elif X == 2 + a[N-1]:
            return p[N-1] + 1
        elif 2 +a[N-1] < X <= 2 + 2*a[N-1]:
            return p[N-1] + 1 + f(N-1, X-2-a[N-1])
        else:
            return 2*p[N-1] + 1
print(f(N,X))