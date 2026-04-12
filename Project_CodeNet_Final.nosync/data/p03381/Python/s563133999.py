N=int(int(input())/2)
X=[int(i) for i in input().split()]


Y=sorted(X)
yu=Y[N]
yd=Y[N-1]
for x in X:
	if x<=yd:
		print(yu)
	else:
		print(yd)
