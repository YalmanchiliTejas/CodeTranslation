# https://atcoder.jp/contests/abc054/tasks/abc054_c

import copy
import sys
input = sys.stdin.readline

# 頂点, 辺の数
N, M = map(int, input().split())

# グラフのリスト
# 各頂点からどこの頂点に向かう辺があるかどうかという情報
Graph_list = [[] for i in range(N)]

# 入力
for i in range(M):
    a, b = map(int, input().split())
    a += -1
    b += -1

    # 無向グラフなのでa, b両方
    Graph_list[a].append(b)
    Graph_list[b].append(a)

ans_count = 0           # 正解の経路の数
visited = [False] * N
visited[0] = True

def dfs(i, current, visited):   
    # 頂点をN個通ったら終了処理
    if i >= N-1:

        # 全ての点に到達している場合
        if all(visited):
            global ans_count
            ans_count += 1
            return 
        return 

    for j in Graph_list[current]:
        if visited[j] == False:
            # 現在地を書き込む
            visited[j] = True
            # 次の点に移動する        
            dfs(i + 1, j, visited)

            visited[j] = False

dfs(0, 0, visited)
print(ans_count)