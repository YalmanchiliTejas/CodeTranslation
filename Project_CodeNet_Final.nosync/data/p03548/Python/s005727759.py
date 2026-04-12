x, y, z = map(int, input().split())
if x < y:
    print(0)
else:
    l = z
    i = 0
    while l + (z+y) <= x:
        l += (z+y)
        i += 1
    print(i)
