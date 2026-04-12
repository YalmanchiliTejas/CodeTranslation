n = raw_input()
ais = map(int, raw_input().split())
s = sum(ais)
cumul = 0
ans = 0
mod = (10 ** 9 + 7)
for i in range(len(ais)):
	cumul += ais[i]
	ans += ais[i] * (s - cumul)
	ans %= mod
print ans % mod
