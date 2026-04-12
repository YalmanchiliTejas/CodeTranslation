import sys
import copy
import math
import bisect
import pprint
import bisect
from functools import reduce
from copy import deepcopy
from collections import deque
from decimal import *


def lcm(x, y):
    return (x * y) // math.gcd(x, y)


if __name__ == '__main__':
    n =int(input())
    a = [int(i) for i in input().split()]
    max = 0
    count =0
    for i in a:
        if max <= i:
            count+=1
            max = i

    print(count)
