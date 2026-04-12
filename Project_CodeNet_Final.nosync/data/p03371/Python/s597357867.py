A,B,C,X,Y=map(int,input().split())
if A+B <= 2*C:
	print(A*X+B*Y)
else:
	if X > Y:
		if A <= 2*C:
			print(2*C*Y+A*(X-Y))
		else:
			print(2*C*X)
	else:
		if B <= 2*C:
			print(2*C*X+B*(Y-X))
		else:
			print(2*C*Y)
