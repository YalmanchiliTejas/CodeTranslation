n = int(input())
h = [int(i) for i in input().split()]

count = 0

for i in range(n):
	over = False
	for j in range(i):
		if h[j] > h[i]:
			over = True

	if not over:
		count += 1

print(count)