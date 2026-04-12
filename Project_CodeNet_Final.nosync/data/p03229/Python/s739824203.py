def solve():
    n = int(input())
    a = sorted(int(input()) for _ in range(n))
    c0 = n // 2 - 1
    c1 = n // 2
    c2 = n // 2 + 1
    ans = 0
    if n & 1:
        for i in range(c0):
            ans -= a[i] * 2
        for i in range(c2 + 1, n):
            ans += a[i] * 2
        ans += -a[c0] + a[c2] + max(-a[c0] + a[c1], - a[c1] + a[c2])
    else:
        for i in range(c0):
            ans -= a[i] * 2
        for i in range(c1 + 1, n):
            ans += a[i] * 2
        ans += -a[c0] + a[c1]
    return ans
print(solve())
