MOD = 10**9+7
n = int(input())
a = list(map(int, input().split()))
s = 0
for x in a:
	s += x
	s %= MOD
ans = 0
for x in a:
	ans += x * (s-x)
	ans %= MOD
ans *= pow(2, MOD-2, MOD)
print(ans%MOD)