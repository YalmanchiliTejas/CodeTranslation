import sys
import math
import collections
import bisect
import itertools
import decimal
import copy
import heapq

# import numpy as np

# sys.setrecursionlimit(10 ** 6)
INF = 10 ** 20
# MOD = 10 ** 9 + 7
MOD = 998244353

ni = lambda: int(sys.stdin.readline().rstrip())
ns = lambda: map(int, sys.stdin.readline().rstrip().split())
na = lambda: list(map(int, sys.stdin.readline().rstrip().split()))
na1 = lambda: list(map(lambda x: int(x) - 1, sys.stdin.readline().rstrip().split()))
flush = lambda: sys.stdout.flush()


# ===CODE===
def main():
    n, x, m = ns()

    total = x
    ai = x
    st = {x}
    prev = [x]

    for i in range(1, n):
        ai = ai ** 2 % m
        total += ai

        if ai in st:
            start = prev.index(ai)
            itrlen = len(prev) - start
            remainlen = n - i

            head = sum(prev[:start])
            itr = prev[start:]
            itrsum = sum(itr)
            remainitrsum = (remainlen // itrlen) * itrsum
            tail = sum(itr[:remainlen % itrlen])
            ans = head + itrsum + remainitrsum + tail
            print(ans)
            exit(0)

        st.add(ai)
        prev.append(ai)

    print(total)


if __name__ == '__main__':
    main()
