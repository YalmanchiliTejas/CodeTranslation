N = int(input())
A = list(map(int, input().split()))
X = sum(A)
ans = 0
for i in range(N):
  ans += A[i]*(X-A[i])
print((ans//2)%(10**9+7))