n1, n2, n3 = map(int, input().split())
n = n2 * 10 + n3
if n % 4:
    print('NO')
else:
    print('YES')