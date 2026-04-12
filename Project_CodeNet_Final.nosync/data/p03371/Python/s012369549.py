A,B,C,X,Y=map(int, raw_input().split())

val1=A*X+B*Y

if X>=Y:
	val2=(C*2)*Y+A*(X-Y)
elif Y>X:
	val2=(C*2)*X+B*(Y-X)

val3=(C*2)*max(X,Y)

print min(val1,val2,val3)


