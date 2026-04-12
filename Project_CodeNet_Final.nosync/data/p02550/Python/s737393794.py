N, X, M = [int(_) for _ in input().split()]
seen = {}
i = 0
A = []
while True:
    if X in seen:
        i2 = seen[X]
        i3 = i
        break
    seen[X] = i
    A += [X]
    i += 1
    X = X**2 % M
if N < i3:
    ans = sum(A[:N])
elif i2 == i3:
    ans = sum(A[:i2]) + A[i2] * (N - i2)
else:
    q, r = divmod(N - i2, i3 - i2)
    ans = sum(A[:i2]) + sum(A[i2:]) * q + sum(A[i2:i2 + r])
print(ans)
