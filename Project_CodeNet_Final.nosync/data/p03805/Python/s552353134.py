n, m = [int(x) for x in input().split(' ')]
 
edges = set([tuple(input().split(' ')) for _ in range(m)])
edges.update([(x[1], x[0]) for x in list(edges)])
 
 
def dfs(node, history):
    ans = 0
    if len(history) == n - 1:
        return 1
 
    nextnodes = [
        x[1] for x in edges if x[1] not in history and x[0] == node and x[1] != node
    ]
    history.add(node)
    for next in nextnodes:
        ans += dfs(next, history)
    history.remove(node)
    return ans
 
 
print(dfs('1', set()))