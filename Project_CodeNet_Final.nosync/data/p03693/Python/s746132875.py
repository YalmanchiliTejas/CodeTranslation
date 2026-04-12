n = input().split()
num = ''
for c in n:
    num += c

if int(num)%4 == 0:
    print('YES')
else:
    print('NO')
