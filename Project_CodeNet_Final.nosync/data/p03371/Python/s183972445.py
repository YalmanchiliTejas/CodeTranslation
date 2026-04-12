a,b,c,x,y = input().split()
A = int(a)
B = int(b)
C = int(c)
X = int(x)
Y = int(y)

min_yen = 0

if(X<Y):
	if(C*2*X < (A*X+B*X)):
		min_yen += C*2*X
		Y -= X

		if(X!=0 and (C*2 < B)):
			min_yen += C*2*Y
		elif(X!=0 and(C*2 >= B)):
			min_yen += B*Y

	else:
		min_yen += A*X

		if(C*2 < B):
			min_yen += C*2*Y
		else:
			min_yen += B*Y


elif(X>=Y):
	if(C*2*Y < (A*Y+B*Y)):
		min_yen += C*2*Y
		X -= Y

		if(X!=0 and (C*2 < A)):
			min_yen += C*2*X
		elif(X!=0 and(C*2 >= A)):
			min_yen += A*X
	else:
		min_yen += B*Y

		if(C*2 < A):
			min_yen += C*2*X

		else:
			min_yen += A*X

print(min_yen)