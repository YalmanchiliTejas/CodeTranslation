a, b, c, x, y = map(int, input().split())

t1 = a*x + b*y
t2 = max(x, y)*2 * c

if x > y:
    t3 = y*2 * c + (x-y) * a
else:
    t3 = x*2 * c + (y-x) * b
    
print(min(t1, t2, t3))