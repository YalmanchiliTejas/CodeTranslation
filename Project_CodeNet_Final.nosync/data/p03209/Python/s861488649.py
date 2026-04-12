N,X=map(int, raw_input().split())

p=[1]
a=[1]
for i in range(N):
	p.append( p[-1]*2+1 )
	a.append( a[-1]*2+3 )

#print "p:::",p
#print "a::::",a

X-=1

def f(N,X):
#	print "f (",N ," , ", X ," ) " ,ans

	if X<0:
		return 0		
	elif N==0:
		return 1
	elif X>=a[N]/2:
		X-=(a[N-1]+2)
		return p[N-1]+1+f(N-1,X)
	else:
		X-=1
		return f(N-1,X)

print f(N,X)

