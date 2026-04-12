n = int(input())
a = list(map(int, input().split()))
MOD = 10 ** 9 + 7
a = [num % MOD if num >= MOD else num for num in a]

sum_list = [0]
for i in range(n):
	sum_list.append((a[i] + sum_list[i]) % MOD)
# print(sum_list)

ans = 0
for i in range(len(a)):
	ans += a[i] * (sum_list[-1] - sum_list[i + 1])
	ans %= MOD

print(ans)