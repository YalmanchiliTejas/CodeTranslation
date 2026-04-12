# A - RGB Cards

# 赤、緑、青色のカードを持っている
# それぞれのカードには 1以上9以下の整数が書かれている

# 赤色のカード r
# 緑色のカード g
# 青色のカード b

# 3つのカード を 左から r g b と並べて、左から整数を読む
# 4の倍数である場合 YES そうでない場合 NO と出力

# r g b を標準入力から得る
r, g, b = map(int, input().split(maxsplit=3))
# print(r, g, b)

# 整数を計算する
# r * 100, g * 10
integer_rgb = (r * 100) + (g * 10) + b
# print(integer_rgb)

# 4で割った余りが 0　の時　YES
# それ以外は NO

if integer_rgb % 4 == 0:
    answer = "YES"
else:
    answer = "NO"

# 結果を出力
print(answer)
