def shik_stone():
	h, w = map(int, raw_input().split(" "))
	m = []
	for i in range(h):
		m.append(str(raw_input()))
	current_most_right_index = 0
	for row in m:
		indices = [i for i, ltr in enumerate(row) if ltr == '#']
		if min(indices)==current_most_right_index:
			if len(indices)!=(max(indices)-min(indices)+1):
				print "Impossible"
				return
			else:
				current_most_right_index = max(indices)
		else:
			print "Impossible"
			return
	print "Possible"


if __name__ == "__main__":
	shik_stone()