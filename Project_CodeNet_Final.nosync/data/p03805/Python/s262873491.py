#!/usr/bin python3
# -*- coding: utf-8 -*-

# 双方向グラフで幅優先探索

def main():
    N, M = map(int, input().split())
    graph = [[] for _ in range(N)]
    #隣接リストの作成
    for i in range(M):
        a, b = map(int, input().split())
        a, b = a-1, b-1
        graph[a].append(b)
        graph[b].append(a)

    from itertools import permutations
    L = list(permutations(range(N)))
    ret = 0
    for l in L:
        fg = 1
        if l[0]!=0:
            continue
        for k in range(N-1):
            if not l[k+1] in graph[l[k]]:
                fg = 0
                break
        if fg == 1:
            ret += fg
    print(ret)

if __name__ == '__main__':
    main()