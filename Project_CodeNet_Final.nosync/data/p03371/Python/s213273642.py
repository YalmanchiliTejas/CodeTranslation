a, b, c, x, y = map(int, input().split())

n_c = min(x, y) * 2
n_a = x - n_c // 2
n_b = y - n_c // 2
amount1 = a * n_a + b * n_b + c * n_c

n_c = max(x, y) * 2
n_a = max(x - n_c // 2, 0)
n_b = max(y - n_c // 2, 0)
amount2 = a * n_a + b * n_b + c * n_c

n_a = x
n_b = y
n_c = 0
amount3 = a * n_a + b * n_b + c * n_c

amount = min(amount1, amount2, amount3)

print(amount)