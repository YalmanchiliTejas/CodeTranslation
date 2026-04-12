def solve(n, h):
    threshold = 0
    res = 0
    for i in range(n):
        if threshold <= h[i]:
            res += 1
        threshold = max(threshold, h[i])
    return res

n = int(input())
h = list(map(int, input().split()))
print(solve(n, h))