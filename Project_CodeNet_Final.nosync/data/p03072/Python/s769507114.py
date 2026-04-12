N = int(input())
H = map(int, input().split()[0:])

mx = 0
ans = 0

for h in H:
	if mx <= h: ans += 1
	mx = max(mx, h)

print(ans)
