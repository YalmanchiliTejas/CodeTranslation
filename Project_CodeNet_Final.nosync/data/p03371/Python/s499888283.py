a, b , c, x, y = map(int, input().split())

s = set()
s.add(a*x + b*y)
if x < y:
    s.add(2*x*c + b*(y-x))
    s.add(2*(x+1)*c + b*(y-x-1))
    s.add(2*y*c)
    print(min(s))
else:
    s.add(2*y*c + a*(x-y))
    s.add(2*(y+1)*c + a*(x-y-1))
    s.add(2*x*c)
    print(min(s))