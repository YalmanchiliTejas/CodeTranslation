import heapq as hq
N = int(input())
peak = []
peak_num = 0

def search(lst, n, length):
	l = 0
	r = length
	while r - l > 1:
		p = (l+r) // 2
		if lst[p] < n:
			r = p
		else:
			l = p
	return l

for i in range(N):
	a = int(input())
	if peak_num == 0:
		peak.append(a)
		peak_num += 1
	elif peak[peak_num-1] >= a:
		peak.append(a)
		peak_num += 1
	else:
		n = search(peak, a, peak_num)
		if peak[n] < a:
			peak[n] = a
		else:
			peak[n+1] = a
print(peak_num)