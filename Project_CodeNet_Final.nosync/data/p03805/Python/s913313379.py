import sys
sys.setrecursionlimit(10**8)
n, m = map(int, input().split())
g = [[] for i in range(n)]
for  i in range(m):
    a, b = map(int, input().split())
    a-=1; b-=1
    g[a].append(b)
    g[b].append(a)

used = [False] * n
ans = 0
def dfs(i, depth=1):
    ret = 0
    if depth==n:
        return 1
    else:
        for e in g[i]:
            if used[e]:
                continue
            used[e] = True
            ret+=dfs(e, depth+1)
            used[e] = False
    return ret

used[0] = True
print(dfs(0, 1))