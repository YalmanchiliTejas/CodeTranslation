N = int(input())
A = [int(a) for a in input().split()]
p = 10 ** 9 + 7

S = [A[0]] * N
for i in range(1, N):
  S[i] = S[i - 1] + A[i]

sum = 0
for i in range(0, N - 1):
	sum += (A[i] * (S[N - 1] - S[i])) % p
print(sum % p)