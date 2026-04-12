a, b, c, x, y = map(int, input().split())
ans = 10 ** 10

for i in range(0, max(x, y) * 2 + 1, 2):
    total = i * c + (max(0, y - i // 2)) * b + (max(0, x - i // 2)) * a
    ans = min(total, ans)
print(ans)