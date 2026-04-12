A,B,C,X,Y = map(int, input().split())
price = {X:A, Y:B}

ans = min(
	2*C*max(X,Y),
	A*X + B*Y,
	price[max(X,Y)]*(max(X,Y)-min(X,Y)) + 2*C*min(X,Y),
)

print(ans)