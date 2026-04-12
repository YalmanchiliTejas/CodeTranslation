import bisect

n = int(input())
nums = [-int(input()) for _ in range(n)]

colors = []
max_val = -1 * (10 ** 10)
for num in nums:
	if num >= max_val:
		colors.append(num)
		max_val = num
	else:
		idx_r = bisect.bisect_right(colors, num)
		colors[idx_r] = num
		max_val = min(colors[-1], max_val)

print(len(colors))

