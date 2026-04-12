N = int(input())
H = list(map(int, input().split()))
h = 0
ans = 0

for i in range(N):
	if h <= H[i]:
		h = H[i]
		ans += 1

print(ans)
