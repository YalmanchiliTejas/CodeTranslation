def f(n, k):
    if k == 0:
        return 1
    if k == 1 and n < 10:
        return n

    s = str(n)
    length = len(s)

    ans = g(length - 1, k)
    for i in range(1, int(s[0])):
        if 1 < k:
            ans += g(length - 1, k - 1)
        else:
            ans += 1
    if 1 < k:
        ans += f(n % 10 ** (length - 1), k - 1)
    elif k == 1:
        ans += 1
    return ans


def g(n, k):
    if n == 0:
        return 0
    if n < k:
        return 0
    if k == 1:
        return n * 9
    elif k == 2:
        return n * (n - 1) // 2 * 9 ** 2
    elif k == 3:
        return n * (n - 1) * (n - 2) // 6 * 9 ** 3


N = int(input())
K = int(input())
print(f(N, K))