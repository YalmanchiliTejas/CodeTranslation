import math
a, b, c, x, y = map(int, input().split())
# print(a, b, c, x, y)

ans = float('inf')
for nc in range(0, max(x, y) * 2 + 1, 2):
    na = x - math.floor(nc / 2)
    if na < 0:
        na = 0
    nb = y - math.floor(nc / 2)
    if nb < 0:
        nb = 0
    total = a * na + b * nb + c * nc
    if total < ans:
        ans = total
    # print(na, nb, nc, total)
print(ans)
