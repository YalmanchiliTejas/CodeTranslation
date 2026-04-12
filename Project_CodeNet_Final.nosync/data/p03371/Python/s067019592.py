A, B, C, X, Y = map(int, input().split())
ret = A * X + B * Y
x = 0
y = 0
c = 0
while (X + Y) * 2 > c :
    c += 2
    x += 1
    y += 1
    tmp = A * max(0, X - x) + B * max(0, Y - y) + c * C
    ret = min(ret, tmp)
print(ret)