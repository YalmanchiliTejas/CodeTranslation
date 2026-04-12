a, b, c, x, y = [int(i) for i in input().split()]

if c < a/2 and c < b/2:
    cost = max(x, y)*2*c
elif c < a/2:
    if x < y:
        cost = x*2*c + (y-x)*b
    else:
        cost = x*2*c
elif c < b/2:
    if y < x:
        cost = y*2*c + (x-y)*a
    else:
        cost = y*2*c
elif c < (a+b)/2:
    cost = min(x, y)*2*c+(x-min(x,y))*a + (y-min(x,y))*b
else:
    cost = x*a+y*b
print(cost)