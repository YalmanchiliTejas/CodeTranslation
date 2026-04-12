a, b, ab, x, y = (int(i) for i in input().split())
costcut = a + b - 2*ab
if costcut<=0:
    total = a*x + b*y
else:
    base = min(x,y)*2*ab
    nokori = abs(x-y)
    if x>y:
        if a>2*ab:
            total = base + nokori*2*ab
        else:
            total = base + nokori*a
    else:
        if b>2*ab:
            total = base + nokori*2*ab
        else:
            total = base + nokori*b
print(total)