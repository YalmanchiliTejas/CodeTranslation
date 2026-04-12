# search smallest i ( s <= i < e ) such that f(i) == True
def bisearch_smallest(f, s, e = None):
	if e == None:
		e = s - 1
		s = 0
	else:
		e -= 1
	
	while s < e:
		m = (s + e) // 2
		if f(m):
			e = m
		else:
			s = m + 1
	
	if s == e and f(s):
		return s
	else:
		return -1

N = int(input())
a_list = [int(input()) for _ in range(N)]

cols = [a_list.pop(0)]

for a in a_list:
	index = bisearch_smallest(lambda i: cols[i] < a, len(cols))
	if index == -1:
		cols.append(a)
	else:
		cols[index] = a

print(len(cols))
