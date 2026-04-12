#カード数字の入力
r, g, b = map(int,input().split())
#判定
a = 100 * r + 10 * g + b

if a % 4 == 0:
    print('YES')
else:
    print('NO')