from bisect import bisect_right
N = int(input())
A = [int(input()) for i in range(N)]
A.reverse()
X = [A[0]]

for i in range(1, N):
    if X[-1] <= A[i]:
        X.append(A[i])
    else:
        idx = bisect_right(X, A[i])
        X[idx] = A[i]

print(len(X))
