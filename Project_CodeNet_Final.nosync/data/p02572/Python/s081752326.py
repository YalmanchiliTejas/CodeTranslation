n = int(input())
A = list(map(int,input().split()))
MOD = 10 ** 9 + 7
ret = 0
S = [A[0]]
for i in range(1, n):
  S.append(S[i-1] +A[i])

for i in range(n):
  ret += A[i] * (S[-1]-S[i])
  ret = ret % MOD
print(ret)