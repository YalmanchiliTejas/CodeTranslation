from math import gcd

from math import factorial as f

from math import ceil, floor, sqrt
import math

import bisect
import re
import heapq

from copy import deepcopy
import itertools
from itertools import permutations

from sys import exit

ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(map(int, input().split()))

yes = "Yes"
no = "No"


def main():
    n = ii()
    a = li()
    s = sum(a)
    ss = 0
    for i in a:
        ss += i**2
    print(((s**2 - ss) // 2) % 1000000007)


main()
