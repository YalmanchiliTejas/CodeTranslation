n = list(map(int, input().split()))
n[0] *= 100
n[1] *= 10

if sum(n) % 4 == 0:
    print('YES')
else:
    print('NO')