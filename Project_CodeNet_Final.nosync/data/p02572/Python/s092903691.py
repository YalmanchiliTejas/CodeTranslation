N = int(input())
A = list(map(int, input().split()))
sumA = sum(A)
K = 10**9+7
ans = 0
diag = 0
for i in range(N):
  diag += A[i]*A[i]
  ans += (A[i]*sumA)
ans = (ans - diag) // 2
ans %= K
print(ans)