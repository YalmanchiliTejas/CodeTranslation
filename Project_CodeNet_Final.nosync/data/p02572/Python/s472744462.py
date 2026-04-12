N = int(input())
A = list(map(int, input().split()))

S = sum(A)
ans = 0

for i in range(N):
  ans += A[i]*(S-A[i])
  
ans = ans // 2
ans = ans % (10**9+7)

print(ans)