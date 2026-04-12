N = int(input())
A = list(map(int, input().split()))
S = [A[0]]
for i in range(1, N):
  S.append(S[i-1] + A[i])
x = 0
for i in range(N):
  x += (A[i] * (S[-1] - S[i])) % 1000000007
x = x % 1000000007
print(x)