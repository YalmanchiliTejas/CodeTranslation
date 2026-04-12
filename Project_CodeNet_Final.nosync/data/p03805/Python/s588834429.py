# ABC054c
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())
l = [set() for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    l[a].add(b)
    l[b].add(a)

visited = [False]*(n+1)


def dfs(i, cnt):
    #print(i, cnt)
    if (cnt == n):
        return 1
    ans = 0
    for j in l[i]:
        if (visited[j]):
            continue
        visited[j] = True
        ans += dfs(j, cnt + 1)
        visited[j] = False
    return ans


visited[1] = True
print(dfs(1, 1))