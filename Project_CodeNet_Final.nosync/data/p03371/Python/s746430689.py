A,B,C,X,Y = map(int, input().split())
a = min(X,Y)
b = min(A+B,2*C)
price=a*b
if X<Y:
  price+=(Y-X)*min(B,2*C)
else:
  price+=(X-Y)*min(A,2*C)
print(price)