a, b, c, x, y = map(int, input().split())
result = 0
if a+b > 2*c:
    if x > y:
        result += 2*c*y
        if a > 2*c:
            result += 2*c*(x-y)
        else:
            result += a*(x-y)
    else:
        result += 2*c*x
        if b > 2*c:
            result += 2*c*(y-x)
        else:
            result += b*(y-x)
else:
    result += a*x + b*y
print(result)