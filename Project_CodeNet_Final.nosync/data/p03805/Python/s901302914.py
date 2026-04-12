n, m = list(map(int, input().split()))
paths = [list(map(int, input().split())) for _ in range(m)]

visited = [1]
rest = [i for i in range(2, n + 1)]
ans = 0

def dfs(num):
    if rest == []:
        # print(visited)
        global ans
        ans += 1
    for i in range(m):
        if num in paths[i]:
            other = paths[i][1 - paths[i].index(num)]
            if other in rest:
                # print(other)
                visited.append(other)
                rest.remove(other)
                # print(visited, rest)
                dfs(other)
                visited.remove(other)
                rest.append(other)

dfs(1)
print(ans)