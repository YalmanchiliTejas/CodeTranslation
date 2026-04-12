a, b, c, x, y = list(map(int, input().split()))

sum1 = a * x + b * y
sum2 = c * 2 * max(x, y)
if x <= y:
    sum3 = c * 2 * x + b * (y - x)
else:
    sum3 = c * 2 * y + a * (x - y)
    
print(min(sum1, sum2, sum3))