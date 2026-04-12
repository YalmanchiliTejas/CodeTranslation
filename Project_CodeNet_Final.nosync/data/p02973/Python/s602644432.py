import bisect

n = int(input())
A = [-int(input()) for i in range(n)]

Q = [A[0]] + [0] * (n+1)
le = 1
for i in range(1, n):
    if Q[le-1] <= A[i]:
        Q[le] = A[i]
        le += 1
    else:
        ind = bisect.bisect_right(Q, A[i], 0, le)
        Q[ind] = A[i]
    # print(Q[:10])

print(le)