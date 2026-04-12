# -*- coding: utf-8 -*-
# スペース区切りの整数の入力
b, c, d = map(int, input().split())
#3桁の数
cin = 100*b+10*c+d
#倍数判定
if cin % 4==0:
  print('YES')
else:
  print('NO')