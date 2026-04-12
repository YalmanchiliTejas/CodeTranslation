n = int(input())
arr = list(map(int, input().split()))
mod = 1000000007
pref = [arr[0]]

for i in arr[1:]:
	pref += [(i + pref[-1]) % mod]

res = 0
for i in range(n - 1):
	res = (res + (arr[i] * (pref[-1] - pref[i])) % mod) % mod
	
print(res)