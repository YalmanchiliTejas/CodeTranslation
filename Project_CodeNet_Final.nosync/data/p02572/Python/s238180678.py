N = int(input())
A = list(map(int, input().split()))
Asum = sum(A) % (10**9 + 7)
ans = 0

for i in range(N):
  ans += A[i] * (Asum-A[i]) % (10**9 + 7)
  Asum -= A[i]

print(ans % (10**9 + 7))