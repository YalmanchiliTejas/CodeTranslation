import sys
import collections

sys.setrecursionlimit(10**6)

def f(X:int, N:int):
    if N == 0:
        return 1
    if N == 1:
        if X == 1:
            return 0
        elif X in [2, 3, 4]:
            return X-1
        else:
            return 3
    l = sum(L[N-1])
    if X == 1:
        return 0
    elif 1 < X <= l+1:
        return f(X-1, N-1)
    elif X == l+2:
        return L[N-1][1] + 1
    elif l+2 < X <= sum(L[N]):
        return L[N-1][1] + 1 + f(X-2-l, N-1)
    else:
        return 2 * L[N-1][1] + 1

def main():
    global L
    N, X = map(int, input().split())
    L = [(0, 1)]
    for i in range(N):
        b, p = L[i]
        b = 2*b + 2
        p = 2*p + 1
        L.append((b, p))
    ans = f(X, N)
    print(ans)

if __name__ == "__main__":
    main()
