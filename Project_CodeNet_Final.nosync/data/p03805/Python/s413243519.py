n, m = map(int, input().split())

graph = [[] for i in range(n)]

for i in range(m):
    a, b = map(int ,input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

transported = [0]
count = 0

def dfs(loc):
    global count
    if graph[loc] != []:
        for i in graph[loc]:
            if i not in transported:
                transported.append(i)
                dfs(i)
                transported.remove(i)

        if len(transported) == n:
            count += 1



for i in graph[0]:
    transported = [0, i]
    dfs(i)

print(count)