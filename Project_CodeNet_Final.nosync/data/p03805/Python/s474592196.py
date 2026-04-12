import copy
n, m = map(int, input().split())
adjacent_list = [[] for i in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    adjacent_list[a].append(b)
    adjacent_list[b].append(a)
ans = 0
def dfs(node,f):
    f.add(node)
    global ans
    if len(f) == n:
        ans += 1
    else:
        for i in adjacent_list[node]:
            if i not in f:
                k = copy.deepcopy(f)
                dfs(i,k)
dfs(1,set())
print(ans)