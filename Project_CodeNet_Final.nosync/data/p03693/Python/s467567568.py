r, g, b = map(int, input().split())
I = int(str(r)+str(g)+str(b))
if I % 4 == 0:
    print('YES')
else:
    print('NO')