a= raw_input().split()

sum = int(a[0])*100 + int(a[1])*10 + int(a[2])

if sum%4 == 0:
	print "YES"
else:
	print "NO"