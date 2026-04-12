N = int(input())
A = list(map(int, input().split()))
cumA = [0]
for i in range(N):
  cumA.append(cumA[-1] + A[i])

ans = 0
M = 10**9 + 7
for i in range(N-1):
  ans += (A[i]*(cumA[N]-cumA[i+1]))
  ans %= M
print(ans)