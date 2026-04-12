import numpy as np

A, B, C, X, Y = map(int,input().split())

value = [A, B]
n_pizza = [X, Y]

# 買う手法は次の3通りしかない
# 全てAとB単品で揃える場合
price_1 = A * X + B * Y
# 全てCで揃える場合
price_2 = 2 * C * max(X, Y)
# 少ない方までCで買って、残りは単品という場合
idx_more_to_buy = n_pizza.index(max(n_pizza))
price_3 = 2 * C * min(X, Y) + value[idx_more_to_buy] * (n_pizza[idx_more_to_buy] - min(X, Y))

ans = min(price_1, price_2, price_3)
print(ans)