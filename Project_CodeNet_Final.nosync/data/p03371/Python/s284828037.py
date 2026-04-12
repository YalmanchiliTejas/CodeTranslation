A, B, C, X, Y = map(int, input().split())
AB = min(C*2,A+B)
A = min(A, C*2)
B = min(B, C*2)
ret = 0
while X + Y > 0:
	if X > 0 and Y > 0:
		ret += AB
		X -= 1
		Y -= 1
	elif X > 0:
		ret += A
		X -= 1
	elif Y > 0:
		ret += B
		Y -= 1
print(ret)