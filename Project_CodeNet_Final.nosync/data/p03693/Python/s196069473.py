r,g,b= map(int, input().split())

N = str(r) + str(g) + str(b)

if int(N)  % 4 == 0:
    print('YES')
else:
    print('NO')
