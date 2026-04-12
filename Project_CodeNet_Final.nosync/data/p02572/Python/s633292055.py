mod = 10**9 + 7

n = int(input())
arr = [int(j) for j in input().split()]

su = sum(arr)
ans = 0
for x in arr:
	ans += x*(su-x)
	ans %= mod
print(ans*pow(2, mod-2, mod) % mod)