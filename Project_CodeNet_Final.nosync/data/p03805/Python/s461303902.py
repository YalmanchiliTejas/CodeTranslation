"""
# 標準入力取得
## 文字列
 = sys.stdin.readline().rstrip()
 = list(sys.stdin.readline().rstrip())

## 数値
 = int(sys.stdin.readline())
 = map(int, sys.stdin.readline().split())
 = list(map(int, sys.stdin.readline().split()))
 = [list(map(int,list(sys.stdin.readline().split()))) for i in range(h)]  # 二次元配列入力　二次元マップみたいな入力のとき

# 0埋め, 小数点出力桁指定時のときの出力
a = 100
b = 0.987654321
print("{0:06d}-{1:6f}".format(a,b))
000100-0.987654

# 文字列をリストに格納
char_list = list("abcd") # ["a","b","c","d"]
"""

import math
import sys
import itertools
import queue
from fractions import gcd

def lcm(a, b):
    return a * b // gcd(a, b)

mod = 1000000007

if __name__ == "__main__":
    n,m = map(int, sys.stdin.readline().split())
    mat = [[0 for i in range(n)]for j in range(n)]

    #隣接行列
    for i in range(n):
        mat[i][i] = 0
    #辺に１を入れる
    for i in range(m):
        a,b = map(int, input().split())
        mat[a-1][b-1] = mat[b-1][a-1] = 1

    cnt = 0

    #辺の値を積でつないでいく方法。一個でもつながらなかったら０になる。
    for each in itertools.permutations(range(n)):
        if each[0] != 0:
            break
        factor = 1
        for i in range(n-1):
            factor *= mat[each[i]][each[i+1]]
        cnt += factor
    print(cnt)

    #dfs（深さ優先探索）