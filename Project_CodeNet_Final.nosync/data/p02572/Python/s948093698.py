n = int(input())

a = list(map(int, input().split()))
sum = sum(a)

result = 0

MOD = 10**9 + 7

for i in range(n):
	sum -= a[i]
	result = (result + a[i] * sum) % MOD

print(result)