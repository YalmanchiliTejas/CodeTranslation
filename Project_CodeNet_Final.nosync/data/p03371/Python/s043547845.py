A, B, C, X, Y = map(int, input().split())

res = float("inf")

for i in range(0, max(X, Y) * 2 + 1, 2):
    Amai = max(0, X - i // 2)
    Bmai = max(0, Y - i // 2)
    res = min(res, A * Amai + B * Bmai + C * i)

print(res)
