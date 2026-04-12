r, g, b = map(int, input().split())

rgb = int(str(r) + str(g) + str(b))
if 0 == rgb % 4:
    print('YES')
else:
    print('NO')
