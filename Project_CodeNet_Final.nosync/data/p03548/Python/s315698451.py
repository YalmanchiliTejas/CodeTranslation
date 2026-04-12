import sys
import math
from fractions import gcd
# import queue
# from collections import Counter
# from itertools import accumulate
# from functools import reduce

def lcm(a, b):
    return a * b // gcd(a, b)

def combination_count(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

def permutations_count(n, r):
    return math.factorial(n) // math.factorial(n - r)

big_prime = 1000000007

"""
# 標準入力取得
## 文字列
 =  sys.stdin.readline().rstrip()
 =  list(sys.stdin.readline().rstrip())

## 数値
 =  int(sys.stdin.readline())
 =  map(int, sys.stdin.readline().split())
 =  list(map(int, sys.stdin.readline().split()))
 =  [list(map(int,list(sys.stdin.readline().split()))) for i in range(N)]
"""

X, Y, Z =  map(int, sys.stdin.readline().split())
print((X - Z) // (Y + Z))