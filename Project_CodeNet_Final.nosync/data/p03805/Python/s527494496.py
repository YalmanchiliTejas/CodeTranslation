def dfs(now,flags):
    global graph
 
    if len(flags) == len(graph)-1:
        return 1

    flags.add(now)
    ans = 0
    for vis in graph[now]:
        if not vis in flags:
            #print(vis,flags)
            ans += dfs(vis,flags)
    flags.remove(now)
    return ans



ans = 0
nums = [int(x) for x in input().split()]
N, M = nums[0], nums[1]
graph = {i:[] for i in range(1,N+1)}

for i in range(M):
    nums = [int(x) for x in input().split()]
    graph[nums[0]].append(nums[1])
    graph[nums[1]].append(nums[0])

print(dfs(1,set()))