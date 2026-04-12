a, b, c, x, y = map(int, input().split())

n = max(int((x + 2 * c - 1) / (2 * c)),
        int((y + 2 * c - 1) / (2 * c)))
ret = float('inf')
for c_i in range(2 * (10 ** 5) + 1):
    a_i = max(x - c_i, 0)
    b_i = max(y - c_i, 0)
    cost = a_i * a + b_i * b + 2 * c_i * c
    ret = min(ret, cost)
print(ret)
