N,M = map(int,input().split())
ab = [list(map(int,input().split())) for i in range(M)]

from collections import defaultdict

memo = defaultdict(list)

for ele in ab:
    memo[ele[0]-1].append(ele[1]-1)
    memo[ele[1]-1].append(ele[0]-1)

que = []
visited = defaultdict(int)
ans = [0]

def dfs(visited,node,pre_node,tmp_sum):
    if tmp_sum == N:
        ans[0] += 1
        return

    for nn in memo[node]:
        if nn == pre_node: continue
        if visited[nn]==1: continue
        visited[nn] = 1
        dfs(visited,nn,node,tmp_sum+1)
        visited[nn] = 0

    return
        
flag = [False]
visited[0]=1
dfs(visited,0,-1,1)

print(ans[0])