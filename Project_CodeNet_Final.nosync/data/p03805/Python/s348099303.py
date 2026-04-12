# Python3 (3.4.3)
import sys
input = sys.stdin.readline

# -------------------------------------------------------------
# function
# -------------------------------------------------------------


# -------------------------------------------------------------
# main
# -------------------------------------------------------------
N,M = map(int,input().split())
AB = [tuple(map(int,input().split())) for _ in range(M)]

A = [[False for _ in range(N)] for _ in range(N)]
for a,b in AB:
    A[a-1][b-1] = True
    A[b-1][a-1] = True

# 頂点を巡る順番を順列で生成する
from itertools import permutations
Ps = permutations([i for i in range(1,N)])

ans = 0
for P in Ps:
    flg = True
    x,y = 0,0
    for p in P:
        y = p
        # 経路がなければ
        if not A[x][y]:
            flg = False
            break
        x = p
    if flg:
        ans += 1

print(ans)