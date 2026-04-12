# import numpy as np
# import math
# import copy
# from collections import deque
import sys
# input = sys.stdin.readline
# sys.setrecursionlimit(10000)


def main():
    S = input()

    res = 'Yes'

    if (S == 'AAA') or (S == 'BBB'):
        res = 'No'

    print(res)



main()
