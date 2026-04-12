n = int(input())
h = list(map(int,input().split()))

ans = 1
max_h = h[0]
for i in range(1,n):
	if max_h <= h[i]:
		ans += 1
		max_h = h[i]
print(ans)
