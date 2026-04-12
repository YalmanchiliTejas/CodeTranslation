from bisect import bisect_right
N = int(input())
A = []
for i in range(N):
    A.append(-int(input()))
INF = float('inf')
D = [INF] * N
for i in range(len(A)):
    D[bisect_right(D, A[i])] = A[i]

print(N - D.count(INF))