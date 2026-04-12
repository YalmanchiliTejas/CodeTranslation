a, b, c, x, y = map(int, input().split())
price = float("inf")
max_iter = max(x, y)*2

for i in range(max_iter):
    a_num = max(x-i, 0)
    b_num = max(y-i, 0)
    price = min(price, a_num*a + b_num*b + 2*i*c)

print(price)