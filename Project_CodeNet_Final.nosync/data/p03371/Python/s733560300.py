a, b, c, x, y = map(int, input().split())
tot = 0
if a + b <= c*2:
    print(a*x+b*y)
    exit()
else:
    tot += min(x, y)*c*2
if x >= y:
    if a <= c*2:
        tot += a*(x-y)
    else:
        tot += c*2*(x-y)
else:
    if b <= c*2:
        tot += b*(y-x)
    else:
        tot += c*2*(y-x)
print(tot)
