import os
import sys
from collections import defaultdict, Counter
from itertools import product, permutations,combinations, accumulate
from operator import itemgetter
from bisect import bisect_left,bisect
from heapq import heappop,heappush,heapify
from math import ceil, floor, sqrt
from copy import deepcopy


def main():
    x = int(input())
    if x < 30:
        print("No")
    else:
        print("Yes")


if __name__ == '__main__':
	main()
