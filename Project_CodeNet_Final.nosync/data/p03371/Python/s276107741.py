A, B, AB, X, Y = map(int, input().split())

if X > Y:
	print(min(A*X+B*Y, A*(X-Y)+AB*2*Y, AB*2*X))
else:
	print(min(A*X+B*Y, AB*2*X+B*(Y-X), AB*2*Y))