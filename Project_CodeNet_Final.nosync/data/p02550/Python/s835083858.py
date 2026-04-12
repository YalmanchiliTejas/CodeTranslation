N, X, M = [int(_) for _ in input().split()]

def f(x, m):
    return x % m

P = [-1 for _ in range(M+1)]

A = [X]
for i in range(N-1):
    v = f(A[-1] ** 2, M)
    A.append(v)
    if P[v] != -1:
        break
    P[v] = i

v = f(A[-1] ** 2, M)
idx = P[v]

S = sum(A[idx+1:])
q, r = divmod(N - len(A), len(A) - idx - 1)

ans = sum(A) + q * S + sum(A[idx+1:idx+1+r])
print(ans)
