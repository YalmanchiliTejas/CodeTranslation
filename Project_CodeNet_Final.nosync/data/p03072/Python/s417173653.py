n = int(raw_input())
h = map(int,raw_input().split())
maxv = 0
count = 0
for i in range(n):
	maxv = max(maxv, h[i])
	if maxv == h[i]:
		count += 1
print count