list = map(int, raw_input().split())
if list[0] > list[1]:
	print "a > b"
elif list[0] < list[1]:
	print "a < b"
else:
	print "a == b"