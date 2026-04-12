N= int(input())
A = list(map(int, input().split()))
MOD = 10 ** 9 + 7

L = [0] * N
L[0] = A[0]
for i in range(1, N):
  L[i] = L[i - 1] + A[i]

ans = 0
for i in range(1, N):
  ans = (ans + A[i] * L[i - 1]) % MOD 
print(ans)