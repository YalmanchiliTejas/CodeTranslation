list = []
dict = {}

while True:
	team,point = map(int,raw_input().split(","))
	if team == 0 and point == 0:
		break
	
	dict[team] = point
	if not point in list:
		list.append(point)
	
list.sort()
list.reverse()

while True:
	try:
		team = int(raw_input())
	except EOFError:
		break
	
	print list.index(dict[team]) + 1