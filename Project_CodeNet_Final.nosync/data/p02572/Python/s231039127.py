from collections import defaultdict, Counter
from itertools import product, permutations, combinations, accumulate
from bisect import bisect_left, bisect
from heapq import heappop, heappush
from fractions import gcd
from math import ceil, floor


def input_list():
    return list(map(int, input().split()))


def input_int():
    return int(input())


N = int(input())
A_LI = input_list()
A_ACC = list(accumulate(A_LI))
MOD = 10 ** 9 + 7
ans = 0
for i in range(1, N):
    ans += A_LI[i] * A_ACC[i - 1]
print(ans % MOD)
