# 入力
r, g, b = map(str, input().split())

# 処理&出力
number = r + g + b
if int(number) % 4 == 0:
    print('YES')
else:
    print('NO')

