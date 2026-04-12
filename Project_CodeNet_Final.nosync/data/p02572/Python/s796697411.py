N = int(input())
A = list(map(int, input().split()))

S = sum(A)
ans = 0
for i in range(N-1):
  a = A[i]
  S -= a
  ans += a * S

print(ans % (10**9+7)  )