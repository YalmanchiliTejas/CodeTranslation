a, b, c, x, y = map(int, input().split())
if x <= y:
    d = x*c*2
    e = (y-x)*b
    abpizza = d+e
    sonomamapizza = a*x+b*y
    pizza = y*c*2
    print(min(abpizza,sonomamapizza,pizza))
else:
    d = y*c*2
    e = (x-y)*a
    abpizza = d+e
    sonomamapizza = a*x+b*y
    pizza = x*c*2
    print(min(abpizza,sonomamapizza,pizza))