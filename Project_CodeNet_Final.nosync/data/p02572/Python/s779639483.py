n = int(input())
a = list(map(int,input().split()))
mod = 10**9+7

S = sum(a) % mod
ans_sum = 0
for i in range(n-1):
	S -= a[i]
	ans_sum += a[i] * S
	
print(ans_sum%mod)
