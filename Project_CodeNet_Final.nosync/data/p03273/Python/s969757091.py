import math
import sys
from itertools import accumulate
from functools import reduce
import queue
from fractions import gcd

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
    = [list(map(int,list(sys.stdin.readline().split()))) for i in range(h)]  # 二次元配列入力　二次元マップみたいな入力のとき
"""

if __name__ == "__main__":
    h,w = map(int, sys.stdin.readline().split())
    a = [list(list(sys.stdin.readline().rstrip())) for i in range(h)]
    c = [list(row) for row in zip(*a)]
    b = [x for x in a if "#" in x]
    c = zip(*[y for y in zip(*b) if "#" in y])
    for d in c:
        print("".join(d))

    # #zip exercize
    # l = [[1, 2, 3], [4, 5, 6]]
    # l_t = list(zip(*l))
    # print(l_t)
