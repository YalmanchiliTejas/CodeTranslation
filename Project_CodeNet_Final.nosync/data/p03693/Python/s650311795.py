li = list(map(int,input().split()))

print('YES' if (li[0] * 100 + li[1] * 10 + li[2]) % 4 == 0 else 'NO')
