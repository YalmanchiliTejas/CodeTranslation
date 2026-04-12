MOD = 998244353
n, S = map(int, input().split())
a = list(map(int, input().split()))
dp1 = [[0 for _ in range(S+1)] for _ in range(n+1)]
dp2 = [[0 for _ in range(S+1)] for _ in range(n+1)]
for i in range(1, n+1): #Lのみ定めたdp1
	for s in range(S+1):
		if s < a[i-1]:
			dp1[i][s] = dp1[i-1][s] % MOD
		elif s == a[i-1]:
			dp1[i][s] = (dp1[i-1][s] + i) % MOD
		else:
			dp1[i][s] = (dp1[i-1][s] + dp1[i-1][max(s-a[i-1],0)]) % MOD

for i in range(1, n+1): #L, Rを定めたdp2
	for s in range(S+1):
		if s < a[i-1]:
			dp2[i][s] = dp2[i-1][s] % MOD
		elif s == a[i-1]:
			dp2[i][s] = (dp2[i-1][s] + i*(n-i+1)) % MOD
		else:
			dp2[i][s] = (dp2[i-1][s] + dp1[i-1][max(s-a[i-1],0)] * (n-i+1)) % MOD

print(dp2[n][s])