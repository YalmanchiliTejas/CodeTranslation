# your code goes here
A,B,C,X,Y = map(int,input().split())

if A + B < 2*C:
	print(X*A+B*Y)
else:
	ans1 = 2*C*max(X,Y)
	if X > Y:
		ans2 = 2*C*Y + A*(X-Y)
	else:
		ans2 = 2*C*X + B*(Y-X)
	print(min(ans1,ans2))