# -*- coding: utf-8 -*-

import sys
import os

N, M = map(int, input().split())
# Node
# M: Edge num

# 隣接リスト
E = [[] for i in range(N)]
#print(E)

for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    E[a].append(b)
    E[b].append(a)
#print(E)

# BFSだとvisitedリストも増えすぎる
# DFSがよい

visited = [False] * N

one_stroke_num = 0
def dfs(v):
    #print('dfs', v)
    global one_stroke_num

    if visited.count(True) == N:
        one_stroke_num += 1
        return
    else:
        # vから行けるところあるか
        for next_i in E[v]:
            if not visited[next_i]:
                # そこに行く
                visited[next_i] = True
                dfs(next_i)
                visited[next_i] = False
        # もう行くところない
        return

visited[0] = True
dfs(0)

print(one_stroke_num)