a, b, c, x, y = map(int, input().split())
min_sum = 0

if (a + b) > (c * 2):
    if x > y:
        min_sum = y * (c * 2)
        if a > (c * 2):
            tankin = c * 2
        else:
            tankin = a
    else:
        min_sum = x * (c * 2)
        if b > (c * 2):
            tankin = c * 2
        else:
            tankin = b
    min_sum += abs(x - y) * tankin
else:
    min_sum = a * x + b * y

print(min_sum)
