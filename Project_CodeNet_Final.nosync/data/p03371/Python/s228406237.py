import sys

A,B,C,X,Y=list(map(int,input().split()))


cost=0
if 2*C<A+B:
	mini=min([X,Y])
	cost+=mini*C*2
	X-=mini
	Y-=mini
	if not X==0:
		if 2*C<A:
			cost+=2*C*X
			X=0
	elif not Y==0:
		if 2*C<B:
			cost+=2*C*Y
			Y=0



cost+=X*A+Y*B

print(cost)