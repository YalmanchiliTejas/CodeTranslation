N = int(input())
A = list(map(int, input().split()))
sa = sum(A)
INF = 10**9+7
ans = 0
for i in range(N):
  sa -= A[i]
  ans += (A[i]*sa)%INF
print(ans%INF)