a, b, c, x, y = map(int, input().split())

sum1 = a * x + b * y

if x > y:
    sum2 = c * 2 * y + a * (x-y)
if x == y:
    sum2 = c * 2 * x
if x < y:
    sum2 = c * 2 * x + b * (y-x)

sum3 = c * 2 * max(x, y)

print(min(sum1, sum2, sum3))