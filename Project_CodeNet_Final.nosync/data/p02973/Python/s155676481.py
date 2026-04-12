from bisect import bisect

# n, k = 5, 4
n = int(input())
seq = []
for i in range(n):
	ele = int(input())
	pos = bisect(seq, -ele)
	if len(seq) <= pos:
		seq.append(-ele)
	else:
		seq[pos] = -ele 
print(len(seq))
