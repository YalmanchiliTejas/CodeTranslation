N = int(input())
A = list(map(int, input().split()))

DIV = 10**9+7
ans = 0
Asum = sum(A)
Asum_sq = Asum**2

for i in range(N):
	ans += A[i]**2

res = (Asum_sq-ans)//2
print(res%DIV)