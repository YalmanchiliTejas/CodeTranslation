ref = ["A","B","C","D","E"]
while 1:
	try:
		d = max([[sum(map(int, raw_input().split())),i] for i in range(5)])
		print ref[d[1]],d[0]
	except:
		break