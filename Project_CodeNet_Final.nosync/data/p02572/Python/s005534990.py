n = int(input())
A = list(map(int, input().split()))

mod = 10**9 + 7

S = [0]
for i in range(n):
  S.append(A[i] + S[i])

ans = 0

for i in range(n):
  tmp = A[i]
  s = S[n] - S[i+1]
  ans = (ans + (tmp * s) % mod) % mod
print(ans)