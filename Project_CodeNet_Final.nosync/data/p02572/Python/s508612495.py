N = int(input())
A = list(map(int, input().split()))

ans = 0
mod = 7 + 10**9

s = sum(A)
for i in range(N):
	s -= A[i]
	ans += s * A[i]
	ans %= mod

print(ans)	