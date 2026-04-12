
## import
from collections import deque # キュー、スタックに利用
import itertools
import math # 数学的計算に利用
# import numpy as np # 行列計算などに利用 # Pypy3ではimport不可
import sys

## 初期設定
# input = sys.stdin.readline # 標準入力の高速化に利用
sys.setrecursionlimit(10**7) # 再帰関数の呼び出し上限を増やす
inf = float('inf')

is_debug = False

n, m = map(int, input().split())

AB = [list(map(int, input().split())) for _ in range(m)]

## 隣接リスト表現でグラフを表現する
# 空の2次元リストの初期化 行数n * 列数0
M = [[] for _ in range(n)]
for a,b in AB:
    M[a-1].append(b-1)
    M[b-1].append(a-1)

if is_debug:
    for row in M:
        print(row)
    print('-----------')

def main():
    '''メイン処理'''

    ok_count = 0
    # 全パターンの順列（要素が同じでも、順番が異なれば異なるとみなすもの）を生成し、
    # 一つずつ、始点から終点までたどり着けるかチェック
    for permutation in itertools.permutations(range(1,n)):
        move_list = list(permutation)
        if is_debug:
            print(move_list)

        # この順列で終点までたどり着けるかチェック
        move_count = 0
        now_n = 0 # 始点は必ず0
        for next_n in move_list:
            if next_n in M[now_n]:
                now_n = next_n
                move_count += 1
            else:
                break
        if move_count == len(move_list):
            ok_count += 1
    
    print(ok_count)
            

if __name__ == "__main__":
    # ファイル実行時に、main()関数を実行
    main()
