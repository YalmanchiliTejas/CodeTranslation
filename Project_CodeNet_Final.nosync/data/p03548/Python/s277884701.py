x, y, z = map(int, input().split())
count = x//(y+z)

if count*(y+z) + z <= x:
    print(count)
else:
    print(count-1)