import math
import copy
from copy import deepcopy
import sys
import fractions
# import numpy as np
from functools import reduce
# import statistics
import decimal
import heapq
import collections
import itertools
from operator import mul

sys.setrecursionlimit(100001)


# input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

# ===FUNCTION===

def getInputInt():
    inputNum = int(input())
    return inputNum


def getInputListInt():
    outputData = []
    inputData = input().split()
    outputData = [int(n) for n in inputData]

    return outputData


def getSomeInputInt(n):
    outputDataList = []
    for i in range(n):
        inputData = int(input())
        outputDataList.append(inputData)

    return outputDataList


def getSomeInputListInt(n):
    inputDataList = []
    outputDataList = []
    for i in range(n):
        inputData = input().split()
        inputDataList = [int(n) for n in inputData]
        outputDataList.append(inputDataList)

    return outputDataList


# ===CODE===

a, b, c, x, y = map(int, input().split())

itr = max(x, y)*2+1

ans = sys.maxsize
for i in range(itr):
    tmpa = max(0, a*(x-i//2))
    tmpb = max(0, b*(y-i//2))
    tmpc = c*i
    tmp_cost = tmpa+tmpb+tmpc
    ans = min(ans, tmp_cost)

print(ans)



