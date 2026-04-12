import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")

def solve():
    n = int(input())
    a = [int(x) for x in input().split()]

    from collections import defaultdict

    dp = defaultdict(lambda : -float('inf'))
    dp[(0, 0, 0)] = 0

    for i in range(1, n + 1):
        max_j = i//2 if i % 2 == 0 else i//2 + 1
        min_j = n//2 - (n - i)//2 if (n - i) % 2 == 0 else n//2 - ((n - i)//2 + 1)
        for j in range(min_j, max_j + 1):
            dp[(i, j, 0)] = max(dp[(i - 1, j, 0)], dp[(i - 1, j, 1)])
            dp[(i, j, 1)] = dp[(i - 1, j - 1, 0)] + a[i - 1]
    print(max(dp[(n, n//2, 0)], dp[(n, n//2, 1)]))
solve()


