a,b,c,x,y = map(int, raw_input().split())
s = 0
if a + b > 2 * c:
    s += min(x,y) * 2 * c
else:
    s += min(x,y) * (a+b)
if x > y:
    if a > 2 * c:
        s += (x-y) * 2 * c
    else:
        s += (x-y) * a
elif y > x:
    if b > 2 * c:
        s += (y-x) * 2 * c
    else:
        s += (y-x) * b
print s
