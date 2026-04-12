#　入力
r, g, b = map(int,input().split())

X = 100 * r + g * 10 + b

if X % 4 == 0:
    print('YES')

else:
     print('NO')