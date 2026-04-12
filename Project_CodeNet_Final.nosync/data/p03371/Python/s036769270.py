# pattern1:Only A-pizza/B-pizza
# pattern2:Only C-pizza
# pattern2:C-pizza & A or B-pizza

a, b, c, x, y = map(int, input().split())

price1 = x * a + y * b
price2 = max(x, y) * 2 * c
price3 = min(x, y) * 2 * c + a * (x - min(x, y)) + b * (y - (min(x, y)))
print(min(price1, price2, price3))
