#!/usr/bin/python3
# -*- coding: utf-8 -*-


"""
https://beta.atcoder.jp/contests/abc054/tasks/abc54_c
"""

import sys
import math
import copy
from inspect import currentframe

def debug_print(*args):
    names = {id(v):k for k,v in currentframe().f_back.f_locals.items()}
    print(', '.join(names.get(id(arg),'???')+' = '+repr(arg) for arg in args), file=sys.stderr)

N, M = map(int, input().split())
graph = [[] for _ in range(N)]

for _ in range(M):
    a, b  = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)
    
# 普通にdfsで行けるイメージなのでそれをする
# パスの数を返す
def dfs(node, visited_list):
    paths = 0
    visited = copy.copy(visited_list)
    if node not in visited:
        visited.append(node)
    debug_print(node)
    debug_print(visited_list)
    if len(visited) == N:
        return 1
    for to in graph[node]:
        if to not in visited:
            paths += dfs(to, visited)
    return paths
        
print(dfs(0, [0]))
        


                                                                                                        
