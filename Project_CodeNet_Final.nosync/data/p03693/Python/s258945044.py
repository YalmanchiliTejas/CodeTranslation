a, b, c = map(int, input().split())
num = (100 * a) + (10 * b) + c
print('YES' if (num % 4) == 0 else 'NO')
