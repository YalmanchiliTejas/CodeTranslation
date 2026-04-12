from bisect import bisect
n = int(input())

vals = []
for _ in range(n):
	a = - int(input())
	idx = bisect(vals,a)
	if idx == len(vals):
		vals.append(a)
	else:
		vals[idx]=a

print(len(vals))