a, b, c, x, y = map(int, input().split())
ans = 10 ** 9
for cn in range(0, max(x, y) * 2 + 1, 2):
    may = max(0, x - cn // 2) * a + max(0, y - cn // 2) * b + cn * c
    ans = min(ans, may)
print(ans)
