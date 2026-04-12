a, b, c, x, y = map(int,input().split())
res = min(a*x + b*y, max(x, y) * 2 * c)

if x < y:
    temp = x * 2 * c + (y - x) * b
else:
    temp = y * 2 * c + (x - y) * a

print(min(res, temp))