N = int(input())
A = list(map(int, input().split()))
r = [A[0]]
m = 10**9 + 7
ans = 0

for i in range(1, N):
  r.append(A[i] + r[i - 1])
  
for i in range(N - 1):
  ans += A[i] * (r[N - 1] - r[i])

ans = ans % m

print(ans)