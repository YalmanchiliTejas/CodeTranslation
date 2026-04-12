import math
import sys
import queue
from collections import Counter
from itertools import accumulate
from fractions import gcd
from functools import reduce


def lcm(a, b):
    return a * b // gcd(a, b)

def combination_count(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

def permutations_count(n, r):
    return math.factorial(n) // math.factorial(n - r)

sys.setrecursionlimit(10000)

mod = 1000000007

"""
# 0埋め, 小数点出力桁指定時のときの出力
a = 100
b = 0.987654321
print("{0:06d}-{1:6f}".format(a,b))
000100-0.987654

# 文字列をリストに格納
char_list = list("abcd") # ["a","b","c","d"]

# 標準入力取得
## 文字列
    = sys.stdin.readline().rstrip()
    = list(sys.stdin.readline().rstrip())

## 数値
    = int(sys.stdin.readline())
    = map(int, sys.stdin.readline().split())
    = list(map(int, sys.stdin.readline().split()))
    = [list(map(int,list(sys.stdin.readline().split()))) for i in range(N)]
"""

if __name__ == "__main__":
    H, W = list(map(int, sys.stdin.readline().split()))
    L = [list(list(sys.stdin.readline().rstrip())) for i in range(H)]

    NL = []
    for l in L:
        if "#" in l:
            NL.append(l)

    # リストの転置
    # https://note.nkmk.me/python-list-transpose/
    L = list(zip(*NL))
    NL2 = []
    for l in L:
        if "#" in l:
            NL2.append(l)

    # もとに戻す
    L = list(zip(*NL2))
    for l in L:
        print("".join(l))