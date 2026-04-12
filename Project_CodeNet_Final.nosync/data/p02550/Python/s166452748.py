def f(x, m):
    return (x**2) % m

N, X, M = map(int, input().split())
A = [X]
S = {X}
while True:
    X = f(X, M)
    if X in S:
        break
    else:
        A.append(X)
        S.add(X)


start = A.index(X)
l = len(A) - start
ans = sum(A[:start])
N -= start

ans += sum(A[start:]) * (N//l)
N %= l

ans += sum(A[start:start+N])
print(ans)