x,y,z = map(int,input().split())
rest = x % (y + z)
quot = x // (y + z)
if rest >= z:
    print(quot)
else:
    print(quot - 1)