#Python

A = map(int, raw_input().split())
#print A[0]
#print A[1]
#print A[2]
n=A[0]*100+A[1]*10+A[2]
#print n

if n%4 == 0:
	print 'YES'
else:
	print 'NO'