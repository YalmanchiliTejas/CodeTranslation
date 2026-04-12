# 入力を受け取る
r, g, b = map(int, input().split())

# 2の倍数かどうか判定する
num = r * 100 + g * 10 + b
if num % 4 == 0:
    print('YES')
else:
    print('NO')