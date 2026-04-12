N = int(input())
A = list(map(int, input().split()))
mod = 10 ** 9 + 7
cs = A[:]
for i in range(1, N):
	cs[i] += cs[i-1]
sum = 0
for i in range(0, N-1):
	sum += A[i] * (cs[-1] - cs[i])
print(sum % mod)