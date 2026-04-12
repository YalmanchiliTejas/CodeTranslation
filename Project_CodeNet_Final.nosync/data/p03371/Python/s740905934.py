# ABC 95, c
A, B, C, X, Y = [int(el) for el in input().split(' ')]
min_total = 10**9
for c in range(max(X, Y) * 2, -1, -2):
    a = max(X - c // 2, 0)
    b = max(Y - c // 2, 0)
    min_total = min(A*a + B*b + C*c, min_total)
print(min_total)
