import sys
import numpy as np
import math  # gcdもあるよ
from collections import deque
from collections import defaultdict
from copy import deepcopy
from itertools import accumulate #リストを与えると累積和を返す
def input(): return sys.stdin.readline().rstrip()
from functools import lru_cache #メモ化
INF = 10**9 + 7

def main():
    n = int(input())
    N = list(map(int,input().split()))
    ans = 0
    """
    for i in range(n - 1):
        #print(N[i] , sum(N[i + 1:]))
        ans += (N[i] * sum(N[i + 1:])) % INF
        ans %= INF
    """
    # ans = sum(N)  /2
    N2 = [pow(i, 2, INF) for i in N]
    N3 = pow(sum(N), 2, INF)
    #print(N2, N3)
    N4 = (N3 - sum(N2))
    if N4 % 2 == 1:
        N4 += INF
    ans = (N4 / 2) % INF
    print(int(ans))
    return 0

if __name__ == "__main__":
    main()