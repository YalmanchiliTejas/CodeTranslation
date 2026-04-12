a, b, c, x, y = map(int, input().split())
l = []
l.append(a*x + b*y)
l.append(2*c * max(x, y))

if x < y:
    l.append(2*c*x + b*(y-x))
elif x > y:
    l.append(2*c*y + a*(x-y))

print(min(l))