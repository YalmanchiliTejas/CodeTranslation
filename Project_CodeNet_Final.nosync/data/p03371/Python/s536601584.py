A,B,C,X,Y  = map(int,input().split())
price_1=A*X+B*Y

if X>Y:
	price_2=C*2*Y+(X-Y)*A
	price_3=C*X*2
else:
	price_2=C*2*X+(Y-X)*B
	price_3=C*Y*2

cheapest=price_1
if price_2<cheapest:
	cheapest=price_2
if price_3<cheapest:
	cheapest=price_3
print(cheapest)
