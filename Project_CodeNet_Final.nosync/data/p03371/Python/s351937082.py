a, b, c, x, y = map(int, input().split())

def f(x,y):
    return x-y if x>y else 0

if (a+b) > 2*c:
    ans = min(2*c*x + f(y,x)*b, 2*c*y + f(x,y)*a)
else:
    ans = a*x + b*y

print(ans)    