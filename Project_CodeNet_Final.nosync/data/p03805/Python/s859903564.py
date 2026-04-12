n, m = map(int, input().split())
g = [[]for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    g[a].append(b) 
    g[b].append(a)

ret = 0
def walk(node, visited):
    global ret
    tmp = visited + [node]
    if len(tmp) == n:
        ret += 1 
    for nd in g[node]:
        if nd not in tmp:
            walk(nd, tmp)
walk(1, [])
print(ret)
