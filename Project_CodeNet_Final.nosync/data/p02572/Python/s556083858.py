n = int(input())
A = list(map(int,input().split()))

sum_a = sum(A)
ans = 0

for i in range(n-1):
	sum_a -= A[i]
	ans += A[i] * sum_a
	ans = ans %(int(1e9 + 7))

print(ans)