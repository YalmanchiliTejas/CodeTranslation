n = int(input())
hlist = list(map(int, input().split()))
h = hlist[0]
m = 1
for i in range(1,n):
	hi = hlist[i]
	if(h <= hi):
		m = m + 1
		h = hi
print(m)