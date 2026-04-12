a, b, c, x, y = map(int, input().split())
m = 0
if a + b < 2 * c:
    m += (a * x) + (b * y)
else:
    m += 2*min([x, y])*c
    if x - y < 0:
        m += min([(abs(x-y) * b), 2*abs(x-y) * c])
    else :
        m += min([(abs(x-y) * a), 2*abs(x-y) * c])
print(m)