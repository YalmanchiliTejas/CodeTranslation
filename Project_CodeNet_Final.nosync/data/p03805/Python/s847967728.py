from itertools import permutations
import sys
input = sys.stdin.readline

N, M = map(int, input().split())

ver = [[] for _ in range(N)]
# 頂点xから移動できる頂点を格納する

for i in range(M):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    ver[a].append(b)
    ver[b].append(a)

ans = 0

for i in permutations(range(1, N)):
    here = 0
    for j in i:
        if j not in ver[here]:
            break
        here = j
    else:
        ans += 1

print(ans)