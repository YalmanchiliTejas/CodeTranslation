MOD = 10**9 + 7
list_size = 1001

f_list = [1] * list_size
f_r_list = [1] * list_size

for i in range(list_size - 1):
	f_list[i + 1] = int((f_list[i] * (i + 2)) % MOD)

f_r_list[-1] = pow(f_list[-1], MOD - 2, MOD)

for i in range(2, list_size + 1):
	f_r_list[-i] = int((f_r_list[-i + 1] * (list_size + 2 - i)) % MOD)

def comb(n, r):
	if n < r:
		return 0
	elif n == 0 or r == 0 or n == r:
		return 1
	else:
		return (((f_list[n - 1] * f_r_list[n - r - 1]) % MOD) * f_r_list[r - 1]) % MOD

def comb_suc(n, r, k):
	if n == r*k:
		return (f_list[n-1] * pow(f_r_list[r-1], k, MOD) * f_r_list[k-1]) % MOD
	else:
		return (f_list[n-1] * f_r_list[n-(r*k)-1] * pow(f_r_list[r-1], k, MOD) * f_r_list[k-1]) % MOD

import sys
def input():
	return sys.stdin.readline()[:-1]

#print(comb(3, 3), comb_suc(3, 3, 1))
n, a, b, c, d = map(int, input().split())
dp = [[0 for _ in range(n+1)] for _ in range(b+1)]
dp[a-1][0] = 1
for i in range(a, b+1):
	for j in range(n+1):
		dp[i][j] += dp[i-1][j]
		if j-c*i >= 0:
			for k in range(c, min(d+1, j//i+1)):
				#print(i, j, k)
				dp[i][j] += dp[i-1][j-k*i] * comb_suc(n-(j-k*i), i, k)
		dp[i][j] %= MOD
#for i in range(b+1):
#	print(dp[i])
print(dp[b][n])