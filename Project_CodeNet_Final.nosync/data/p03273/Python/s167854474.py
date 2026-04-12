# -*- coding: utf-8 -*-
# 整数の入力
h, w = map(int, input().split())
# h * w個の文字を入力
a = [[0]*w]*h
for i in range(h):
    a[i] = list(input())

# 空行削除
a = [ai for ai in a if "".join(ai) != "."*w]

# 空列削除, atに転置させたresultを詰め込む
at = []
for aj in zip(*a):
    if "".join(aj) != "."*len(aj):
        at.append(aj)

# 結果の出力
for ai in zip(*at):
    print("".join(ai))
