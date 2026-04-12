import numpy as np
def f(a, b, c, x, y):
    Min = np.inf
    for use_c in range(max(x, y) * 2 + 1):
        price = use_c * c + max(0, x - use_c // 2) * a + max(0, y - use_c // 2) * b
        if price < Min:
            Min = price
    print(Min)

a, b, c, x, y = map(int, input().split())
f(a, b, c, x, y)
