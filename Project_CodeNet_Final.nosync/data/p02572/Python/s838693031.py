N = int(input())
A = list(map(int, input().split()))
T = sum(A)
ans = 0
for i in range(N):
  T -= A[i]
  ans += A[i] * T
  ans %= 10 ** 9 + 7
print(ans)