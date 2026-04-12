#!/usr/local/bin/python3

N, X, M = map(int, input().split())

def f(x, m):
    return x**2 % m

check = [False for _ in range(M)]
d = [X]
max_x = 0
for _ in range(1, N+1):
    X = f(X, M)
    if check[X]:
        break
    else:
        check[X] = True
    d.append(X)

idx = d.index(X)
ans = sum(d[:idx])
N -= idx
d = d[idx:]

sumd = sum(d)
ans += N//len(d) * sumd

ans += sum(d[:N%len(d)])

print(ans)
