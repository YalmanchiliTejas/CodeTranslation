a, b, c, x, y = map(int, input().split())

def f(x,y):
    return x-y if x>y else 0

print(min(2*c*x + f(y,x)*b, 2*c*y + f(x,y)*a, a*x+b*y))
