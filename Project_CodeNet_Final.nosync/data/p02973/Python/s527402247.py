import bisect

N = int(input())
A = [-1]*N

for _ in range(N):
    val = int(input())
    n = bisect.bisect_left(A, val)
    A[n-1] = val

print(N-A.count(-1))