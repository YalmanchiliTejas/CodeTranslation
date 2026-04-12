a, b, c, x, y = map(int, input().split())
same = 0
diff = 0
if x>y:
    diff=min(a*(x-y), 2*c*(x-y))
    same = y
elif y>x:
    diff=min(b*(y-x), 2*c*(y-x))
    same = x
else:
    same = x
print(min((a+b)*same, 2*c*same) + diff)