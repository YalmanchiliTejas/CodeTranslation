import itertools
n, m = map(int, input().split())
lst = [[] for _ in range(n)]
for _ in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    lst[x].append(y)
    lst[y].append(x)

perms = list(itertools.permutations( [_ for _ in range(n)]))

ans = 0
flg = 0
for _ in perms:
    if _[0] == 0:
        visited = [0 for _ in range(n)]
        visited[0] = 1
        for i in range(n-1):
            st = _[i]
            ed = _[i+1]
            if ed in lst[st] and visited[ed] == 0:
                visited[ed] = 1
            else:
                pass
        if sum(visited) == n:
            ans += 1
    else:
        pass          
print(ans)