inpt = map(int, raw_input().split())
n = 100 * inpt[0] + 10 * inpt[1] + inpt[2]
if n % 4 == 0:
	print 'YES'
else:
	print 'NO'
