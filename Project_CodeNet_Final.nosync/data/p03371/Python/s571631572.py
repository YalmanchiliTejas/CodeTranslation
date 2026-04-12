A,B,C,X,Y=map(int,input().split())
Z = min(X, Y)
price1 = min((A+B)*Z, 2*C*Z)
if X > Y:
    price2 = min((X-Y)*A, 2*(X-Y)*C)
elif X < Y:
    price2 = min((Y-X)*B, 2*(Y-X)*C)
else:
    price2 = 0
print(price1 + price2)