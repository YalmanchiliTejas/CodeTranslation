inf = (5000 * 10 ** 5) * 3

a, b, c, x, y = map(int, input().split())

ret = inf
for cnt_ab in range(max(x, y) * 2 + 1):
    d = cnt_ab // 2

    cnt_a = max(0, x - d)
    cnt_b = max(0, y - d)

    t = cnt_ab * c + cnt_a * a + cnt_b * b
    ret = min(ret, t)
print(ret)
