import sys

A, B, C, X, Y = map(int, input().split())

if A+B <= 2*C:
	print(A*X + B*Y)
	sys.exit()

else:
	ans = 0
	temp = min(X,Y)
	ans = 2*C*temp
	X -= temp
	Y -= temp

	if X > 0:
		ans += X * min(A, 2*C)
	else:
		ans += Y * min(B, 2*C)

	print(ans)