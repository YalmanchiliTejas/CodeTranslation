n = int(input())
h = list(map(int, input().split()))

max_h = 0
ans = 0
for i in range(n):
	if max_h <= h[i]:
		ans += 1
	if max_h < h[i]:
		max_h = h[i]

print(ans)
