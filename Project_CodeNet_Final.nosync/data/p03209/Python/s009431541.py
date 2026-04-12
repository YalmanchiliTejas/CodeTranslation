N, X = list(map(int, input().split()))

a = [1]
p = [1]
for i in range(N):
    a.append(3 + 2 * a[i])
    p.append(1 + 2 * p[i])

def f(N, X):
    # レベルNバーガーの下からX層までに含まれるパティPの枚数
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= 1 + a[N - 1]:
        return f(N - 1, X - 1)
    else:
        return p[N - 1] + 1 + f(N - 1, X - 2 - a[N - 1])

print(f(N, X))