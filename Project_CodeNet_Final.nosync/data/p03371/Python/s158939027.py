# -*- coding: utf-8 -*-
"""
Created on Sat Apr 21 21:25:13 2018

@author: Kim
"""

IN = input().split()
A = int(IN[0])
B = int(IN[1])
C = int(IN[2])
X = int(IN[3])
Y = int(IN[4])

#そのまま買う
As = A * X
Bs = B * Y
ALLSUM = As + Bs

#ハーフをどちらかに合わせる
Cmax = 2 * max(X,Y) * C
Cmin = 2 * min(X,Y) * C

#ハーフの場合で小さい方に合わせた時の差分とその額
sabunkosuu = max(X,Y) - min(X,Y)
if X > Y:
    sabungaku = A * sabunkosuu
elif X < Y:
    sabungaku = B * sabunkosuu
else:
    sabungaku = 0

#そしてそれを足した時の額
halfmin = Cmin + sabungaku 

#全部比べる
ANS = min(ALLSUM, Cmax, halfmin)
print(ANS)