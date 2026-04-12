a, b, c, x, y = map(int, input().split())

n = min(x, y)
p1 = min(n*a+n*b, 2*n*c)

nn = max(x, y) - n
if x > y:
    p2 = min(nn*a, 2*nn*c)
else:
    p2 = min(nn*b, 2*nn*c)
print(p1+p2)
