#!/usr/bin/env python3
import sys
import itertools
import collections
from queue import Queue
import functools
import math
import numpy as np

INF = 10**9


def main():
    H, W = [int(x) for x in input().split()]
    a = [input() for _ in range(H)]

    # print(a)
    ans = []
    for item in a:
        flag = False
        for v in item:
            if v == "#":
                flag = True
        if flag == True:
            ans.append(item)
    a = ans
    H = len(a)

    # 列
    ans = [[] for x in range(H)]
    for i in range(W):
        flag = False
        for item in a:
            if item[i] == "#":
                flag = True
        if flag == True:
            for j in range(H):
                ans[j].append(a[j][i])
    for item in ans:
        print(*item, sep="")
    pass


if __name__ == '__main__':
    main()
