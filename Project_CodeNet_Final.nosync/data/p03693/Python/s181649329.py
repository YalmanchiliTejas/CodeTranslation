n, m, k = map(int, input().split())
nmk = 100 * n + 10 * m + k
if nmk % 4 == 0:
    print('YES')
else:
    print('NO')