A, B, C, X, Y= map(int, input().split())

if C < (A+B)/2:
	if X < Y:
		if 2*C < B:
			print(C*2*X + 2*C*(Y-X))
		else:
			print(C*2*X + B*(Y-X))
	else:
		if 2*C < A:
			print(C*2*Y + 2*C*(X-Y))
		else:
			print(C*2*Y + A*(X-Y))
else:
	print(A*X + B*Y)