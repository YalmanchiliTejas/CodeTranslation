a = map(str,input().split())
b=''.join(map(str, a))
if int(b)%4==0:
    print('YES')
else:
    print('NO')
