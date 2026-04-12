n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def my_permutations(nums, t, path):
    if len(nums) == 0:
        path.append(t)
        return
    for i in range(len(nums)):
        my_permutations(nums[:i] + nums[i + 1:], t + [nums[i]], path)

def dfs(graph, permu, n):
    visited = [False] * (n + 1)
    next_nodes = set([1])
    for p in permu:
        if visited[p]:
            return False
        if p not in next_nodes:
            return False
        visited[p] = True
        next_nodes = set(graph[p])
    return True

path = []
my_permutations([i for i in range(1, n + 1)], [], path)
ans = 0
for permu in path:
    if permu[0] != 1:
        continue
    if dfs(graph, permu, n):
        ans += 1
print(ans)