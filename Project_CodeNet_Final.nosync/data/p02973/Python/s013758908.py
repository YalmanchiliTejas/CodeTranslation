from bisect import bisect_right as br
N = int(input())
X = [-1] * N
for _ in range(N):
    a = int(input())
    i = br(X, a-1) - 1
    X[i] = a

print(N - X.count(-1))