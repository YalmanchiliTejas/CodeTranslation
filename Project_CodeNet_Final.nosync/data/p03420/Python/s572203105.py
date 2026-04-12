def f(n, m, k):
    return (n + 1) // m * (m - k) + max(0, (n + 1) - (n + 1) // m * m - k) - (1 if k == 0 else 0)

n, k = [int(x) for x in input().split()]
print(sum(f(n, m, k) for m in range(k + 1, n + 1)))