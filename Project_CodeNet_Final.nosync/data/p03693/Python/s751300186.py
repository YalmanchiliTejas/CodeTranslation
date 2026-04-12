a, b, c = map(int, input().split())

S = 100 * a + 10 * b + c

if (S%4==0):
    print('YES')
else:
    print('NO')