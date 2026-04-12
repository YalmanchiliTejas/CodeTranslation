ref = ["A","B","C","D","E"]
while True:
	try:
		d = sorted([[sum(map(int, raw_input().split())),i] for i in range(5)])[-1]
		print ref[d[1]],d[0]
	except:
		break