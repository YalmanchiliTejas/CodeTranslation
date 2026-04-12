import sys
A, B, C, X, Y = map(int, input().split())

Z = max(X,Y)
W = min(X,Y)

if Z % 2 == 1:
  Zeven = Z + 1
else:
  Zeven = Z

if W % 2 == 1:
  Weven = W + 1
else:
  Weven = W

# 個別
price1 = X*A + Y*B

# 全部Cで賄う（超えても良い）
price2 = C * Z * 2

# X,YのMAXが奇数の時、MAX-1までをCで賄う。端数はABでやる
if Z % 2 == 0:
  price3 = price2
else:
  price3 = C * (Z-1)*2 + A * max(0, X - Z + 1) + B * max(0,Y - Z + 1)

# 少ない方に合わせてCでまかない、端数はAかBでやる（超えるver)
price4 = C * W * 2 + A * max(0,X-W) + B * max(0,Y-W)

# 少ない方に合わせてCでまかない、端数はAかBでやる（超えないver)
if W % 2 == 0:
  price5 = price4
else:
  price5 = C * (W-1) * 2+ A * max(0,X - W + 1) + B * max(0,Y - W + 1)

#print(price1, price2, price3, price4, price5)
print(min(price1,price2,price3,price4,price5))