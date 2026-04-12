N = int(input())
A = list(map(int, input().split()))
m = 10**9 + 7
r = 0
ans = 0

for i in range(1, N):
  r += A[i - 1]
  ans += A[i] * r
  
ans = ans % m

print(ans)