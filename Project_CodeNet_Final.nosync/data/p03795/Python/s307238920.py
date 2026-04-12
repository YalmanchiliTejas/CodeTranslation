n = input()
if int(n) // 15 >= 1:
	print(int((800 * int(n)) - (int(n) // 15 * 200)))
else:
	print(800 * int(n))