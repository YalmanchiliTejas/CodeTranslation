a, b, c, x, y = map(int, input().split())
pata = a*x + b*y

patb = c * (2 * max(x,y))

if x >= y:
    patc = c * (2*y) + a*(x-y)
else:
    patc = c * (2*x) + b*(y-x)
print(min(pata,patb,patc))
