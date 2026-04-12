A, B, C, X, Y = map(int, input().split())


if 2*C<A and 2*C<B:
	print(2*C*max([X,Y]))
elif 2*C<A:
	if X<Y:
		print(2*C*X+B*(Y-X))
	else:
		print(2*C*X)
elif 2*C<B:
	if Y<X:
		print(2*C*Y+A*(X-Y))
	else:
		print(2*C*Y)
elif 2*C<A+B:
	if Y<X:
		print(2*C*Y+A*(X-Y))
	else:
		print(2*C*X+B*(Y-X))

else:
	print(A*X+B*Y)