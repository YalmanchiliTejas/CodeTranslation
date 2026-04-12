N, X = [int(x) for x in input().split()]
h = [1]
b = [1]
for i in range(N):
    h.append(3 + h[i] * 2)
    b.append(1 + b[i] * 2)
def rec(n: int, x: int):
    if (n == 0):
        return 0 if x <= 0 else 1
    mid = 1 + h[n-1] + 1
    if (x < mid):
        return rec(n-1, x-1)
    if (x == mid):
        return b[n-1] + 1
    if (mid < x):
        return b[n-1] + 1 + rec(n-1, x-mid)
print(rec(N, X))
