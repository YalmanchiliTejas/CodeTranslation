n = int(input())
h = list(map(int,input().split()))

c = 0
highest = 0
for i in range(n):
	if highest <= h[i]:
		c += 1
		highest = h[i]

print(c)