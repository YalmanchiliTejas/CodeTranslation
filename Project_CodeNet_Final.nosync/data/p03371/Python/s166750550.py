a, b, c, x, y = list(map(int, input().split(' ')))

result = a * x + b * y

mx = max([x, y])

for i in range(1, mx + 1):
    tmp = a * max([(x - i), 0]) + b * max([(y - i), 0]) + c * 2 * i

    if result > tmp:
        result = tmp

print(result)

