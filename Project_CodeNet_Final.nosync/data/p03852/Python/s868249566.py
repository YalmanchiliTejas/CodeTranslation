# import numpy as np
# import math
# import copy
# from collections import deque
import sys
input = sys.stdin.readline
# sys.setrecursionlimit(10000)


def main():
    c = input().rstrip()

    s = 'aeiou'

    if c in s:
        print('vowel')
    else:
        print('consonant')



main()
