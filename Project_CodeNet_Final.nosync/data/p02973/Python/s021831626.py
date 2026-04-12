from bisect import bisect as bl

N = int(input())
A = []
for i in range(N):
    A.append(int(input()))

def lds(X: list):
    L = [-X[0]]
    for x in X[1:]:
        if L[-1] <= -x:
            L.append(-x)
        else:
            L[bl(L, -x)] = -x
    return len(L)

print(lds(A))