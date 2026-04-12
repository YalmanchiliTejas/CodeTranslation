n = int(input())
h = list(map(int, input().split()))

ans = 0
maxi = -1

for i in range(n):
	if maxi <= h[i]:
		ans = ans + 1
	maxi = max(maxi, h[i])

print(ans)