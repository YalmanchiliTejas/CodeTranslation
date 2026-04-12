A,B,C,X,Y=map(int,input().split())
if X>=Y:
	Z=A*(X-Y)
else:
	Z=B*(Y-X)
print(min(A*X+B*Y,min(X,Y)*2*C+Z,C*max(X,Y)*2))