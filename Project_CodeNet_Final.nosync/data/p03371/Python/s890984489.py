a, b, c, x, y = map(int, input().split())

d = (a + b) - 2 * c

sep = a * x + b * y

ab_x = 2 * x * c
ab_y = 2 * y * c
sum = 0

if d < 0:
    print(sep)
    exit()
elif x > y:
    sum = a * (x - y) + ab_y
    if sum > ab_x:
        print(ab_x)
    else:
        print(sum)
else:
    sum = b * (y - x) + ab_x
    if sum > ab_y:
        print(ab_y)
    else:
        print(sum)