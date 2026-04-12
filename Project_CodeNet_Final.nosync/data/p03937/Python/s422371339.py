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

import numpy as np

import math

import collections
import itertools
import bisect

def check(maiz):
    for i in range(h):
        for j in range(w):
            count = 0
            if i > 0 and maiz[i-1][j] =="#":
                count+=1
            if i <h-1 and maiz[i+1][j] =="#":
                count+=1
            if j > 0 and maiz[i][j-1] =="#":
                count+=1
            if j <w-1 and maiz[i][j+1] =="#":
                count+=1
            if count > 2 and  maiz[i][j] == "#":
                return False
    return True

if __name__ == '__main__':
    h, w = map(int, input().split())
    count =0
    flag =False
    maiz=[]
    for i in range(h):
        s = input()
        count+=s.count("#")
        maiz.append(list(s))

    if count == h+w-1 and check(maiz):
        print("Possible")
    else:
        print("Impossible")