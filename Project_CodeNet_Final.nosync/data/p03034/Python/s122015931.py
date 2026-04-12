import sys
import time

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n = int(input())
    s = list(map(int, readline().split()))
    ans = 0

    for c in range(1, n):
        dp = 0
        visited = set()
        for k in range(1, (n - 1) // c):
            forward = k * c
            backward = n - 1 - k * c
            if forward == backward:
                break
            if (forward or backward) in visited:
                break
            visited.add(forward)
            visited.add(backward)
            dp = dp + s[n - 1 - k * c] + s[k * c]
            ans = max(ans, dp)

    print(ans)


if __name__ == '__main__':
    main()
