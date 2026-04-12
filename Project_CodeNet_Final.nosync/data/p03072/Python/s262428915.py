N = int(input())
H = list(map(int, input().split()))
h = H[0]
ans = 1
for i in range(1, N):
	if H[i] >= h:
		ans += 1
	h = max(H[i], h)
print(ans)
