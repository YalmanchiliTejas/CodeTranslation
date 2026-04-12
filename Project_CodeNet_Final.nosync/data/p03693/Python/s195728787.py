R,G,B = map(str,input().split())

res = int(R+G+B)

if res % 4 == 0:
    print('YES')
else:
    print('NO')

