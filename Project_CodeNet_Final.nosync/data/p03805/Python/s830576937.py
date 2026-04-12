#ABC054 C - One-stroke Path

# v：現在の頂点 seen:訪問済みの頂点
def dfs(v,seen):
    if all(seen):
        return 1
    res = 0
    # 頂点ｖに隣接しているnvを探索していく
    for nv in G[v]:
        if seen[nv]:
            continue
        seen[nv]=True
        res += dfs(nv,seen)
        # 次の隣接頂点nvを探索した時の探索経路で、
        # 今回探索した隣接頂点nv通る可能性があるので
        # 元に戻しておく
        seen[nv]=False
    return res

n,m = map(int, input().split())
G = [[] for _ in range(n)]
seen = [False]*n
res = 0

for i in range(m):
    a,b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

# 頂点1を訪問済みとして探索を開始する
seen[0]=True
print(dfs(0,seen))

