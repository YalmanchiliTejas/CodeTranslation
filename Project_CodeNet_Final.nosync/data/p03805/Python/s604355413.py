import copy
n, m = map(int, input().split())
adjacent_list = [[] for i in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    adjacent_list[a].append(b)
    adjacent_list[b].append(a)
ans = 0

def dfs(node, finished):
    #print("node {}  finished {}".format(node, finished))
    finished.add(node)
    global ans
    if len(finished) == n:
        ans += 1
    else:
        for i in adjacent_list[node]:
            if i not in finished: 
                passed = copy.deepcopy(finished)
                dfs(i, passed)
dfs(1,set([1]))
print(ans)
