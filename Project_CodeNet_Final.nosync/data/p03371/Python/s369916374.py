a, b, c, x, y = map(int, input().split())

if x < y:
    x, y = y, x
    a, b = b, a

ans = min([a*x+b*y,
           c*2*y+a*(x-y),
           2*c*x,])

print(ans)
