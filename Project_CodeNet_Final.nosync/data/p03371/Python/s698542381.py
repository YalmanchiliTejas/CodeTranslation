a, b, ab, x, y = map(int, input().split())

min_value = a * x + b * y

max_num = max(x, y)

for i in range(2, max_num * 2 + 1, 2):
    # print(i)
    value = ab * i + a * max(0, x - i // 2) + b * max(0, y - i // 2)
    # print(value)
    min_value = min(min_value, value)

print(min_value)
