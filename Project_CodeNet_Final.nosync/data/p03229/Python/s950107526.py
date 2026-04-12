import sys
readline = sys.stdin.readline
def solve():
    n = int(input())
    a = sorted(int(readline()) for _ in range(n))
    c0 = n // 2 - 1
    c1 = n // 2
    c2 = n // 2 + 1
    ans = 0
    if n & 1:
        ans = sum(a[c2 + 1:]) * 2 - sum(a[:c0]) * 2 - a[c0] + a[c2] + max(-a[c0] + a[c1], - a[c1] + a[c2])
    else:
        ans = sum(a[c1 + 1:]) * 2 - sum(a[:c0]) * 2 - a[c0] + a[c1]
    return ans
print(solve())
