r,g,b = map(str,input().split())
list_C = [r,g,b]
num = int(''.join(list_C))
if num%4 == 0:
    print('YES')
else:
    print('NO')