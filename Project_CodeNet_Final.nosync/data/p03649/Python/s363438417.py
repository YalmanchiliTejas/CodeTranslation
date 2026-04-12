N = int(input())
A = [int(a) for a in input().split()]
ans = 0
while max(A) >= N:
    for i in range(N):
        if A[i] >= N:
            t = A[i] // N
            A = [A[j] - t * N if j==i else A[j] + t for j in range(N)]
            ans += t

print(ans)