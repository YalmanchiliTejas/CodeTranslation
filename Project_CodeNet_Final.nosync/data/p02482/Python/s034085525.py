rawInput = raw_input();
rawInput = rawInput.split(" ")
listNum = map(int, rawInput)

if listNum[0] < listNum[1]:
	print "a < b"
elif listNum[0] > listNum[1]:
	print "a > b"
else:
	print "a == b"