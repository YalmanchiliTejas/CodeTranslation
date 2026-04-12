a, b, c, x, y = map(int, input().split())
tot = min(a*x + b*y, 2*c*max(x,y))
if x > y:
    tot = min(tot, a*(x-y)+2*c*min(x,y))
elif x < y:
    tot = min(tot, b*(y-x)+2*c*min(x,y))
print(tot)