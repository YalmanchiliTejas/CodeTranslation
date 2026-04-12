a, b, c, x, y = map(int, input().split())

ans = 10 ** 18
for i in range(0, 2 * max(x, y) + 1, 2):
    tmp = i * c
    if x - i // 2 > 0:
        tmp += (x - i // 2) * a
    if y - i // 2 > 0:
        tmp += (y - i // 2) * b
    ans = min(ans, tmp)
print(ans)
