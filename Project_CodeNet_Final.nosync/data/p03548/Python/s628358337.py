X,Y,Z = list(map(int,input().split()))
out = 0
now = 0
if X>=Y+Z+Z:
    out += 1
    now += Y+Z+Z
    while X>=now+Y+Z:
        now += Y+Z
        out += 1
    print(out)
