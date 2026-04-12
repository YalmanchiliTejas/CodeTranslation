from copy import deepcopy

n,m = map(int,input().split())
AB = [list(map(int,input().split())) for i in range(m)]

graph = [[] for i in range(n)]
for a,b in AB:
    a,b = a-1,b-1
    graph[a].append(b)
    graph[b].append(a)

path = [0]*n
path[0] = 1
# print(graph)
# print(path)

def func(i,path,ans):
    # print(i,path)
    if path.count(1) == n:
        return ans+1
    flag = 1
    for g in graph[i]:
        if path[g] == 0:
            flag = 0
            next_path = deepcopy(path)
            next_path[g] = 1
            ans = func(g,next_path,ans)
    return ans
ans = func(0,path,0)
print(ans)