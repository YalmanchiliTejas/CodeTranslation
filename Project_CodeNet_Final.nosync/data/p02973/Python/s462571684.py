from bisect import bisect_left

N = int(input())
A,c = list(range(N)),[]
for i in range(N):
	A[i] = int(input())

for x in reversed(A):
	p = bisect_left(c, x+1)
	if p == len(c):
		c.append(x)
	else:
		c[p] = x
print(len(c))