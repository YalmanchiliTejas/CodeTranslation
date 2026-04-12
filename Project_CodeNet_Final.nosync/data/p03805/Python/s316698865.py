n,m = map(int,input().split())
matrix = [[] for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    matrix[a-1].append(b-1)
    matrix[b-1].append(a-1)

check = [False for i in range(n)]

ans = 0
def dfs(v):
    global ans

    if check.count(True) == n:
        ans += 1
        return
    else:
        for next in matrix[v]:
            if not check[next]:
                check[next] = True
                dfs(next)
                check[next] = False
        return

check[0] = True
dfs(0)

print(ans)