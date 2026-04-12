n = [int(_) for _ in input().split()]
if len(n) == 3 and all(1 <= item <= 9 for item in n):
    print('YES' if 0 == (100 * n[0] + 10 * n[1] + n[2]) % 4 else 'NO')
else:
    print('hoge!')