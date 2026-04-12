A, B, C, X, Y = map(int, input().split())
num = float("inf")
for i in range(0, (10 ** 5) * 2 + 1, 2):
    num = min(num, max(0, X - i // 2) * A + max(0, Y - i // 2) * B + C * i)
print(num)