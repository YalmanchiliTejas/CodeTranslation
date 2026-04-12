f = lambda: map(int, input().split())
n,m = f()
path = [[0 for _ in range(n)] for _ in range(n)]
for _ in range(m):
    a,b = f()
    path[a-1][b-1]=path[b-1][a-1]=1

ans = 0


def dfs(pStack):
    global ans
    if len(pStack) == n:
        ans += 1
        pStack.pop()
        return
    cNode = pStack[-1]
    for nNode in range(n):
        if path[cNode][nNode] and not nNode in pStack:
            pStack.append(nNode)
            dfs(pStack)
    pStack.pop()


dfs([0])
print(ans)
