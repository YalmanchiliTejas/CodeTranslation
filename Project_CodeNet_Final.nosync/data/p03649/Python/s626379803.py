N = int(input())
A = list(map(int, input().split()))
k = 0
while max(A) > N - 1:
    S = 0
    for i in range(N):
        S += A[i] // N

    for i in range(N):
        A[i] = A[i] - (A[i] // N) * N + S - A[i] // N

    k += S

print(k)
