a, b, c, x, y = map(int, input().split())

res = 0
tmp = 0
pair = False
if a // 2 + b // 2 < c:
    res = a+b
else:
    res = c*2

tmp = res * min(x, y)

if x > y:
    print(tmp + abs(x - y) * min(res, a))
else:
    print(tmp + abs(x - y) * min(res, b))
