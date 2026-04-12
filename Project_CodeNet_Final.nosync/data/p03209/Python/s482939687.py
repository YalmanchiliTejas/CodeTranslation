N, X = map(int, input().split())


def count(N, X):
    if N == 0:
        return 1
    if X == 1:
        return 0
    elif 1 < X < 2**(N+1) - 1:
        return count(N-1, X-1)
    elif X == 2**(N+1) - 1:
        return 2**N
    elif 2**(N+1) - 1 < X:
        return 2**N + count(N-1, X-2**(N+1)+1)


print(count(N, X))