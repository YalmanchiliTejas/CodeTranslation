while True:
	try:
		list = [1, 2, 6, 5, 4, 3]
		list2 = [0, 0, 0, 0, 0, 0]
		judge = 1
		n = input()
		if n == 0:
			break
		else:
			for i in range(n):
				order = raw_input()
				if order == 'North':
					list2[0] = list[1]
					list2[1] = list[2]
					list2[2] = list[3]
					list2[3] = list[0]
					list2[4] = list[4]
					list2[5] = list[5]
				if order == 'East':
					list2[5] = list[0]
					list2[4] = list[2]
					list2[0] = list[4]
					list2[2] = list[5]
					list2[1] = list[1]
					list2[3] = list[3]
				if order == 'West':
					list2[4] = list[0]
					list2[5] = list[2]
					list2[2] = list[4]
					list2[0] = list[5]
					list2[1] = list[1]
					list2[3] = list[3]
				if order == 'South':
					list2[1] = list[0]
					list2[2] = list[1]
					list2[3] = list[2]
					list2[0] = list[3]
					list2[4] = list[4]
					list2[5] = list[5]
				if order == 'Right':
					list2[4] = list[1]
					list2[5] = list[3]
					list2[3] = list[4]
					list2[1] = list[5]
					list2[0] = list[0]
					list2[2] = list[2]
				if order == 'Left':
					list2[5] = list[1]
					list2[4] = list[3]
					list2[1] = list[4]
					list2[3] = list[5]
					list2[0] = list[0]
					list2[2] = list[2]
				list = [list2[0], list2[1], list2[2], list2[3], list2[4], list2[5]]
				judge += list[0]
		print judge
	except EOFError:
		break
