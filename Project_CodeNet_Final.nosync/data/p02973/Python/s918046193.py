import bisect
N = int(input())
A = [int(input()) for _ in range(N)]

S = [0] * N

end = N
for i in range(N):
    j = bisect.bisect_left(S, A[i], end, N)
    if j <= end:
        S[j-1] = A[i]
        end -= 1
    else:
        S[j-1] = A[i]

print(N-end)
