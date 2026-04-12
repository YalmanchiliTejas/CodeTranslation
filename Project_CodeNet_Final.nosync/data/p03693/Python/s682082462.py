input_line_1 = raw_input()
x, y, z = input_line_1.split(" ")
if (int(y) * 10 + int(z)) % 4 == 0:
	print "YES"
else:
	print "NO"