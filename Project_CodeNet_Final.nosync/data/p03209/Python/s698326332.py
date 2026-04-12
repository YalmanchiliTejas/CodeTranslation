def f_(N, X, a, p):
    if X == 1:
        return 0
    elif X <= 1 + a[N - 1]:
        return f(N - 1, X - 1, a, p)
    elif X == 2 + a[N - 1]:
        return p[N - 1] + 1
    elif X <= 2 + 2 * a[N - 1]:
        return p[N - 1] + 1 + f(N - 1, X - 2 - a[N - 1], a, p)
    else:
        return 2 * p[N - 1] + 1
        
def f(N, X, a, p):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= 1 + a[N - 1]:
        return f(N - 1, X - 1, a, p)
    else:
        return p[N - 1] + 1 + f(N - 1, X - 2 - a[N - 1], a, p)
        

N, X = map(int, input().split())
a = [1 for i in range(N + 1)]
p = [1 for i in range(N + 1)]
a[0] = 1;
p[0] = 1;

for i in range(1, N + 1):
    a[i] = 2 * a[i - 1] + 3
    p[i] = 2 * p[i - 1] + 1
    
print(f(N, X, a, p))