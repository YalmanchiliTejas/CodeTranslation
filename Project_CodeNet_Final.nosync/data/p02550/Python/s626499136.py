import math


def solve():
    N, X, M = map(int, input().split())

    if N == 1:
        return X % M

    A = [X]
    vis = [-1] * M
    vis[X] = 0
    for i in range(1, M + 1):
        X = X ** 2 % M
        if vis[X] != -1:
            pref = A[:vis[X]]
            cycle = A[vis[X]:]
            break
        A.append(X)
        vis[X] = i

    n_full_period = (N - len(pref)) // len(cycle)
    suffix_length = N - len(pref) - n_full_period * len(cycle)

    ans = 0
    ans += sum(pref)
    ans += sum(cycle) * n_full_period
    ans += sum(cycle[:suffix_length])
    return ans

print(solve())