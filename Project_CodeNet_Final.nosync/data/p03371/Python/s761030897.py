A, B, C, X, Y = map(int, input().split())

"""
ABピザの購入数(0~2 * max(X, Y)で全探索)
"""
min_price = 10 ** 10
for i in range(2 * max(X, Y) + 1):
    c_price = C * i
    a_price = A * max(0, (X - i//2))
    b_price = B * max(0, (Y - i//2))
    min_price = min(min_price, a_price+b_price+c_price)
print(min_price)
