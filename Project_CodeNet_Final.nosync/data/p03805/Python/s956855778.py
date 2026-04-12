n, m = map(int, input().split())

sign = []
for i in range(n):
    sign.append("o")
    
graph = []
for i in range(n):
    graph.append([])
    
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    for j in range(n):
        if a == j:
            graph[j].append(b)
        if b == j:
            graph[j].append(a)

def dfs(x, i=0):
    sign[x] = "x"
    if sign == ["x" for k in range(n)]:
        return i + 1
    for j in graph[x]:
        if sign[j] == "o":
            sign[j] = "x"
            i = dfs(j, i)
            sign[j] = "o"
    return i 

print(dfs(0))
