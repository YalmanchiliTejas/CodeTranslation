N = int(input())
*H, = map(int, input().split())

count = 0
max_h = 0
for h in H:
	if max_h <= h:
		count += 1
		max_h = h

print(count)
