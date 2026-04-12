mod = 10**9 + 7
n = int(input())
a = list(map(int,input().split()))
prefix = list()
sum = 0
for i in a:
	sum += i
	prefix.append(sum)

res = 0
for i in range(0,n):
	t = (a[i] * (prefix[n - 1] - prefix[i])) % mod
	res = (t + res) % mod

print(res)