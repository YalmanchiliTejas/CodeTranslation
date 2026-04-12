a, b, c, x, y = map(int, input().split())
if c <= (a/2) and c <= (b/2):
    print(c*max(x, y)*2)
elif c <= (a + b) / 2:
    if x <= y:
        if b > 2*c:
            print(c*x*2+2*c*(y-x))
        else:
            print(c*x*2+b*(y-x))
    else:
        if a > 2*c:
            print(c*y*2+2*c*(x-y))
        else:
            print(c*y*2+a*(x-y))
else:
    print(a*x+b*y)