import sys
import copy
sys.setrecursionlimit(1000000000)

def dfs(start, total, usedNodes):
    if start in usedNodes:
        return 0
    
    if total <= 1:
        return 1
    
    indices = findNodeIndex(start)
    if len(indices) == 0:
        return 0

    count = 0
    for i in indices:
        nextNode = PATHS[i][1] if PATHS[i][0] == start else PATHS[i][0]
        count += dfs(nextNode, total - 1, usedNodes + [start])
    return count

def findNodeIndex(node):
    return [i for (i, row) in filter(lambda x: (x[1][0] == node or x[1][1] == node), [(i, row) for i, row in enumerate(PATHS)])]

N, M = map(int, input().split())
PATHS = [list(map(int, input().split())) for _ in range(M)]
#start = findNodeIndex(1, PATHS)

print(dfs(1, N, []))