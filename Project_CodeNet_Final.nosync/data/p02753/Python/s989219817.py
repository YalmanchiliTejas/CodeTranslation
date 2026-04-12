# -*- coding: utf-8 -*-
# 整数の入力
station = input()

#一文字ずつ取り出して反映する
if station[0] == station[1] == station[2]:
  print("No")
else:
  print("Yes")