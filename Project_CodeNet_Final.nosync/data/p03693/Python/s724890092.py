a = list(map(str, input().split()))
n = ''
for i in a:
    n += i
if int(n)%4==0:
    print('YES')
else:
    print('NO')