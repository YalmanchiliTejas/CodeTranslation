import math, sys
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from copy import deepcopy
from functools import lru_cache
from heapq import heapify, heappop, heappush
from itertools import accumulate, combinations, permutations
input = sys.stdin.readline
mod = 10**9 + 7
ns = lambda: input().strip()
ni = lambda: int(input().strip())
nm = lambda: map(int, input().split())
nl = lambda: list(map(int, input().split()))

def main():
    a, b, c, x, y = nm()

    if a + b <= 2*c:
        ans = a*x + b*y
    elif int(a if x > y else b) <= 2*c :
        ans = 2*c*min(x, y) + int(a if x > y else b)*abs(x - y)
    else:
        ans = 2*c*max(x, y)

    print(ans)


if __name__ == '__main__':
    main()