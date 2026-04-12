import sys
for l in sys.stdin:
	if int(l) >= 30:
		print("Yes")
	else:
		print("No")