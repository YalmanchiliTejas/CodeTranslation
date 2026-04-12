# -*- coding: utf-8 -*-
import itertools
import sys
import math
from functools import lru_cache

# 1整数
# n = int(input())

# 空白区切り2変数
from queue import Queue
from operator import mul
from functools import reduce
from queue import Queue
from operator import mul
from functools import reduce
from functools import lru_cache

input = sys.stdin.readline

# N個整数
# a, b, c = list(map(int, input().split()))

# 1整数
n = int(input())

# 空白区切りリスト整数
b = list(map(int, input().split()))

# 空白区切り文字列
# t, d = input().split()

ret = 0

for i in range(n):
    flag = True
    for j in range(i):
        if b[j] > b[i]:
            flag = False
    if flag == True:
        ret += 1
print(ret)
