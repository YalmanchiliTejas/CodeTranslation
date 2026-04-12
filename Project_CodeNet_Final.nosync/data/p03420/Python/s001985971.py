def calc(N, K):
    if K == 0:
        return N**2
    result = 0
    for b in range(K + 1, N + 1):
        n, m = divmod(N, b)
        result += (b - K) * n
        if m >= K:
            result += m - K + 1
    return result

N, K = [int(_) for _ in input().split()]
print(calc(N, K))
