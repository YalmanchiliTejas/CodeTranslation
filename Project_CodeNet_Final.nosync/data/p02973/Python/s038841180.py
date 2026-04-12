from bisect import bisect_left

N,A,c = int(input()),[],[]
for i in range(N):
	A.append(int(input()))
A.reverse()

for x in A:
	p = bisect_left(c, x+1)
	if p == len(c):
		c.append(x)
	else:
		c[p] = x
print(len(c))