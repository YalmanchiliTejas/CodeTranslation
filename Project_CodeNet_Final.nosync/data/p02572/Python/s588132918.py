NUM = 1000000000 + 7
N = int(input())
total = 0
A = list(map(int, input().split()))
S = [0] * N
S[0] = A[0]
for i in range(1, len(A)):
  S[i] = S[i-1] + A[i]; 
for i in range(N):
  total += A[i] * (S[N-1] - S[i]);
print(total%NUM)