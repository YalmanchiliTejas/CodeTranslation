N, X = map(int, input().split())
b, p = [1], [1]

for i in range(N):
    b.append(b[i] * 2 + 3)
    p.append(p[i] * 2 + 1)
    
def f(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= b[N-1] + 1:
        return f(N-1, X-1)
    else:
        return p[N-1] + 1 + f(N-1, X-2-b[N-1])
    
print(f(N, X))