a, b, c, x, y = map(int, input().split())
min_sum = 0

if (a + b) > (c * 2):
    if x > y:
        min_sum = y * (c * 2)
        if a > (c * 2):
            min_sum += (x - y) * (c * 2)
        else:
            min_sum += (x - y) * a
    else:
        min_sum = x * (c * 2)
        if b > (c * 2):
            min_sum += (y - x) * (c * 2)
        else:
            min_sum += (y - x) * b
else:
    min_sum = a * x + b * y

print(min_sum)
