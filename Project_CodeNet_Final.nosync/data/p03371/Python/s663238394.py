a, b, ab, x, y = (int(x) for x in input().split())
if x>y:
    tmp = x
    x = y
    y = tmp
    tmp = a
    a = b
    b = tmp

if a+b < 2*ab:
    print(a*x+b*y)
elif b < 2*ab:
    print(b*(y-x)+ab*2*x)
else:
    print(2*ab*y)

