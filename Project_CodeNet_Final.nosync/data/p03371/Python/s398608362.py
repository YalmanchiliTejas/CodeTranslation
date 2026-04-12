from numba import njit


@njit
def solve(a, b, c, x, y):
    ans = 10000000000000000
    for i in range(100000 + 1):
        X = i * (2 * c) + max(0, x - i) * a + max(0, y - i) * b
        ans = min(ans, X)
    return ans


a, b, c, x, y = map(int, input().split())
print(solve(a, b, c, x, y))
