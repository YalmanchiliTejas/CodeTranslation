three =  list(map(int, input().split()))
r = three[0]
g = three[1]
b = three[2]
g = str(g)
b = str(b)
gb = g + b
gb = int(gb)

if gb%4 ==0:
    print('YES')
else:
    print('NO')