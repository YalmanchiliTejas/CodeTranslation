import bisect

N = int(input())
A = [int(input()) for _ in range(N)]

A.reverse()
ans = [A[0]]

for i in range(1, N):
    n = bisect.bisect_right(ans, A[i])
    if A[i] >= ans[-1]:
        ans.append(A[i])
    else:
        ans[n] = A[i]

print(len(ans))
