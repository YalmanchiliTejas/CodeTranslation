x, a, b = map(int, input().split())

num = str(x) + str(a) + str(b)
num = int(num)
if num % 4 == 0:
    print('YES')
else:
    print('NO')