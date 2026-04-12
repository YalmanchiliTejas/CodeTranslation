import sys


def solve(x):
    return (x - k) * (n // x) + max(0, n % x - k + 1)


n, k = map(int, input().split())

if k == 0:
    print(n**2)
    sys.exit()


ans = 0
for i in range(k + 1, n + 1):
    ans += solve(i)

print(ans)