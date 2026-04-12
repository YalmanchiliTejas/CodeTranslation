x = map(int,raw_input().split(' '))
a = x[0]
b = x[1]
if a>b:
	print 'a > b'
elif a<b:
	print 'a < b'
else:
	print 'a == b'