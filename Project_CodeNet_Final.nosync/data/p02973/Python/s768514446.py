n = int(raw_input())
ais = [int(raw_input()) for _ in range(n)]
tails = []
import bisect
for a in ais:
	if not(tails) or (tails[-1] >= a):
		tails.append(a)
	else:
		# maintain a decreaing tails
		986643321
		lo,hi = 0, len(tails) - 1
		while(lo<hi):
			med= (lo + hi)/2
			if tails[med] < a:
				hi = med
			else:
				lo = med + 1
		tails[lo] = a
print len(tails)