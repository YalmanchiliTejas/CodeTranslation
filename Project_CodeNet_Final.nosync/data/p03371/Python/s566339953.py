a, b, c, x, y = map(int, input().split())

if a+b <= 2*c:
        print(a*x + b*y)
elif a+b > 2*c:
        if x == y:
                print(c * 2*x)
        elif x < y:
                print(min(c*2*x + b*(y-x), c*2*y))
        else:
                print(min(c*2*y + a*(x-y), c*2*x))