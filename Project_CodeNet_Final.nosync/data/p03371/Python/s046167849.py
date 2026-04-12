input_list = list(map(int, input().split(' ')))
a, b, c, x, y = input_list

total = 0
if a + b > 2 * c:
    total += 2 * c * min(x, y)
else:
    total += (a + b) * min(x, y)

if x == y:
    pass
elif x > y:
    if a > 2 * c:
        total += 2 * c * (x - y)
    else:
        total += a * (x - y)
else:
    if b > 2 * c:
        total += 2 * c * (y - x)
    else:
        total += b * (y - x)

print(total)
