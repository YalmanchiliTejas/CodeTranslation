L = list(map(str, input().split()))

num = int(''.join(L))

if num % 4 == 0:
    print('YES')
else:
    print('NO')