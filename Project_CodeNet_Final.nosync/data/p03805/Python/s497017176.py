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
def dfs(itr, n, cnt=0):
    ans = 0
    if len(itr)==n:
        return 1
    else:
        ans = cnt
        for e in g[itr[-1]]:
            if used[e]:
                continue
            used[e] = True
            ans+=dfs(itr+[e], n)
            used[e] = False
    return ans

used[0] = True
print(dfs([0], n, 0))