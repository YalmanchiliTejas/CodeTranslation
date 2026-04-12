from collections import Counter
from collections import defaultdict
from collections import deque
from functools import reduce
import math
import itertools
import heapq
#import numpy as np
import bisect
import sys
#import sympy
sys.setrecursionlimit(10**6)


def bfs(s, n, node):
    # 頂点が探索済みかどうかのチェック配列
    check = [False for _ in range(n)]
    check[s] = True
    # 次見る頂点を格納するキュー
    queue = deque([s])
    visited_num = 1

    # 問題固有の配列
    #color_check=[[True for _ in range(l)] for _ in range(n)]
    color = [-1 for _ in range(n)]
    color[s] = 0

    while visited_num < n:
        # グラフが全連結ではない場合
        if len(queue) == 0:
            # 空配列を返す
            # 現状までの計算済み配列を返してもいいと思う
            return color

        now_vertex = queue.popleft()
        # インデックスがない場合は
        for next_vertex in node[now_vertex]:

            if check[next_vertex] == True:
                continue

            queue.append(next_vertex)
            check[next_vertex] = True

            # 問題固有の計算
            color[next_vertex] = color[now_vertex]+1
            visited_num += 1

    return color


mod = 10**9+7
# n=int(input())
# n,m=list(map(int,input().split()))
# a=list(map(int,input().split()))
def ceil(x, y): return (x+y-1)//y
def input_list(): return list(map(int, input().split()))


n = int(input())
if n<30:
    print("No")
else:
    print("Yes")