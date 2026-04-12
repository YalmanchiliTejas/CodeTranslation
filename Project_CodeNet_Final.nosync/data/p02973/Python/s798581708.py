from bisect import bisect_right
N = int(input())
A = [int(input()) for i in range(N)]
A = [-a for a in A]

X = []
for a in A:
    i = bisect_right(X, a)
    if i == len(X):
        X.append(a)
    else:
        X[i] = a


print(len(X))
