# -*- coding: utf-8 -*-

# Nを取得
n = int(input())

# Xiを取得
xs = list(map(int, input().split()))

# 昇順にソートしたXiを取得
xs_sorted = sorted(xs)

# Xiの個数およびその1/2の値を取得
l = len(xs_sorted)
l_mid = int(l / 2)

# iが全体の1/2より小さい時、大きい時の中間値をそれぞれ取得
xs_mid_1 = xs_sorted[l_mid - 1]
xs_mid_2 = xs_sorted[l_mid]

# 結果を出力
for x in xs:
    if x < xs_mid_2:
        print("{}".format(xs_mid_2))
    else:
        print("{}".format(xs_mid_1))
