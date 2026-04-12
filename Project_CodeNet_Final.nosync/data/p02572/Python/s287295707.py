N = int(input())
A = list(map(int, input().split()))
ans = 0
S = sum(A) - A[0]
for i in range(0, N-1):
  ans = (ans + A[i] * S) % (10**9+7)
  S -= A[i+1]
print(ans)