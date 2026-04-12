import bisect

N = int(input())
A = [0] * N
for i in range(N):
  A[i] = int(input())

B = [A[N - 1]]
for i in reversed(range(0, N - 1)):
  if A[i] >= B[-1]:
    B.append(A[i])
  else:
    index = bisect.bisect_right(B, A[i])
    B[index] = A[i]
print(len(B))