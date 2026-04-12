a, b, c = map(int, input().split())
A = 100*a + 10*b + c

if A % 4 == 0:
    print('YES')
else:
    print('NO')
