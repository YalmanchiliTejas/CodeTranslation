import sys
import numpy as np


def main():
    n, k = [int(x) for x in input().split()]
    if k == 0:
        print(n * n)
        sys.exit()
    ans = 0
    for b in range(k + 1, n + 1):
        ans += ((b - k) * (n // b)) + max(0, (n % b) - k + 1)
    print(ans)


main()
