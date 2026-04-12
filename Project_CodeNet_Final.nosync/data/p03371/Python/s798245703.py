A,B,C,X,Y=map(int,input().split())

D=min(A+B,2*C)

price=min(X,Y)*D

Z=max(X,Y)-min(X,Y)

if X>Y:
   price+=Z*min(A,2*C)
elif X<Y:
   price+=Z*min(B,2*C)

print(price)