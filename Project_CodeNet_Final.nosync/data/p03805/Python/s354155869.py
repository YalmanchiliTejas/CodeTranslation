from itertools import permutations
import sys


def input(): return sys.stdin.readline().strip()
def I(): return int(input())
def LI(): return list(map(int, input().split()))
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def S(): return input()
def LS(): return input().split()


INF = float('inf')
n, m = LI()
edges = [[False] * n for _ in range(n)]  # edges[i][j] : 頂点 i から j へ向かう辺がある
for _ in range(m):
    a, b = LI()
    a -= 1
    b -= 1
    edges[a][b] = True
    edges[b][a] = True

# ハミルトン路 ： 頂点を一度だけ通る路のこと
# ハミルトン閉路 : 全頂点を一度だけ通る閉路のこと
# 関連 : オイラー路 ： 全辺を一度だけ通る路のこと

# 開始地点である頂点 1 をぞの板頂点の順列を全列挙
permu = list(permutations(range(1, n)))

ans = 0
for p in permu:
    now = 0  # 頂点 1 から順列にある頂点の順番を参考に各頂点に向かってみる
    is_ok = True  # 条件を満たすか
    for j in p:
        if edges[now][j]:
            now = j
        else:
            is_ok = False
            break
    if is_ok:
        ans += 1


print(ans)
