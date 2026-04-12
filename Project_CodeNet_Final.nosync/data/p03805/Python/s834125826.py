import sys

def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n,m = LI()

graph = [[] for _ in range(n)]
for _ in range(m):
    a, b = LI()
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)  # 有向グラフなら消す

seed = [False] * n
seed[0] = True

def dfs(v,seed):
    if all(seed):
        return 1
    ans = 0
    for i in graph[v]:
        if seed[i]:
            continue
        seed[i] = True
        ans += dfs(i,seed)
        seed[i] = False
    return ans
print(dfs(0,seed))