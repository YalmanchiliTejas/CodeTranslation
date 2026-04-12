N = int(input())
A = list(map(int, input().split()))
s = sum(A)
res = 0
mod = 10**9 + 7
for i in range(N-1):
	s -= A[i]
	res += s*A[i]
print(res%mod)