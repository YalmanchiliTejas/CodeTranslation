from itertools import accumulate, permutations, combinations, combinations_with_replacement, groupby, product
# import math
# import numpy as np  # Pythonのみ！
# from operator import xor
# import re
# from scipy.sparse.csgraph import connected_components  # Pythonのみ！
# ↑cf.  https://note.nkmk.me/python-scipy-connected-components/
# from scipy.sparse import csr_matrix
# import statistics # Pythonのみ
# import string
import sys
sys.setrecursionlimit(10 ** 5 + 10)


def input(): return sys.stdin.readline().strip()


def resolve():
    """
    https://qiita.com/drken/items/4a7869c5e304883f539b#3-3-dfs-%E3%81%AE%E5%86%8D%E5%B8%B0%E9%96%A2%E6%95%B0%E3%82%92%E7%94%A8%E3%81%84%E3%81%9F%E5%AE%9F%E8%A3%85
    cf. https://atcoder.jp/contests/abc138/submissions/13273052
    """

    N, M = map(int, input().split())  # 頂点数，辺数
    # グラフ入力受取 (ここでは無向グラフを想定)
    G = [[] for _ in range(N)]
    for i in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        G[a].append(b)
        G[b].append(a)
    ans = 0

    for i in permutations(range(N)):
        flag = True
        if i[0] != 0:
            continue
        nn=0
        for j in range(N-1):
            if i[j+1] not in G[nn]:
                flag = False
            nn=i[j+1]
        if flag:
            ans += 1
    print(ans)


resolve()