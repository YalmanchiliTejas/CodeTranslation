x, y, z = map(int, input().split())
per = y + z
ans = x // per
if ans * per + z > x:
    print(ans - 1)
else:
    print(ans)