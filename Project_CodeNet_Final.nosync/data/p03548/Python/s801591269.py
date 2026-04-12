x, y, z = (int(i) for i in input().split())

ans, mod = divmod(x, y+z)
if mod >= z:
    print(ans)
else:
    print(ans-1)