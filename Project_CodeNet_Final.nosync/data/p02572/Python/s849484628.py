
mod = 10 ** 9 + 7


N = int(input().rstrip())
As = list(map(int, input().rstrip().split()))
ans = 0
add = 0

for i in range(N):
	add += As[i]
	add %= mod
ans = add * add % mod

for i in range(N):
	ans -= As[i] * As[i] % mod
	if (ans < 0):
		ans += mod

ans *= int((mod + 1) / 2)
ans %= mod

print(ans)