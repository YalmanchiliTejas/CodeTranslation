N = int(input())
A = list(map(int, input().split()))
S = 0
ans = 0
for k in range(N):
  S = S + A[k]

for i in range(N-1):
  S = S - A[i]
  ans = ans + S * A[i]

ans = ans % (10**9 + 7)
print(ans)

