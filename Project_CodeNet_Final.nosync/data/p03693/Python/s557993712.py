# 文字列として、red, green, blue の数字を出力
red_num, green_num, blue_num = map(str, input().split())

# ３つの文字列を合わせる。
join_three_num = red_num + green_num + blue_num

# 文字列を数字に変換。
three_digit_int = int(join_three_num)

if three_digit_int % 4 == 0:
    print('YES')
else:
    print('NO')