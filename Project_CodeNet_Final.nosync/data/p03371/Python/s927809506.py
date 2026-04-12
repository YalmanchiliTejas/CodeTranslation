A,B,C,X,Y=map(int,input().split())
price_sum_1=A*X+B*Y
if min(X,Y)==X:
    price_sum_2=C*X*2+(Y-X)*B
else:
    price_sum_2=C*Y*2+(X-Y)*A

if max(X,Y)==X:
    price_sum_3=C*X*2
else:
    price_sum_3=C*Y*2
    
print(min(price_sum_1,price_sum_2,price_sum_3))