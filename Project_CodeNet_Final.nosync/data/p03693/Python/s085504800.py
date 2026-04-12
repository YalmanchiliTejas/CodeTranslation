a = list(map(str,input().split()))
s = ''.join(a)
if int(s)%4 == 0:
    print('YES')
else:
    print('NO')
