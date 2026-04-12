import sys
readline = sys.stdin.readline

A,B,C,X,Y = map(int,readline().split())

XY = 0
ans = 10 ** 9
while XY // 2 <= max(X,Y):
  price = XY * C
  price += max(X - (XY // 2), 0) * A + max(Y - (XY // 2), 0) * B
  if ans > price:
    ans = price
  XY += 1
    
print(ans)