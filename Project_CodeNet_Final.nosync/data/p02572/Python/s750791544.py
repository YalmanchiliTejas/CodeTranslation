N = int(input())
A = list(map(int, input().split()))
S = sum(A)%(10**9+7)
ans = 0
for i in range(N-1):
  S -= A[N-i-1]
  ans += S*A[N-i-1]%(10**9+7)
print(ans%(10**9+7))