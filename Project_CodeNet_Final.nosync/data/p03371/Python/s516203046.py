a, b, c, x, y = map(int, input().split())
# 3通り
# 1: ax+by
# 2: 2c*large
# 3: 2c*small + (a/b) * diff

tar1 = a * x + b * y
tar2 = 2 * c * max(x, y)

dif = abs(x - y)
if (x > y):
    tar3 = 2 * c * y + a * (x - y)
else:
    tar3 = 2 * c * x + b * (y - x)


ans = min(tar1, tar2, tar3)


# ---------
print(ans)
