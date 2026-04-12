def count_path(graph, node, visited):
    if node in visited: return 0
    if len(visited)==len(graph)-1: return 1
    visited.add(node)
    res=0
    for i in range(len(graph)):
        if graph[node][i]:
            res+=count_path(graph, i, visited)
    visited.remove(node)
    return res

def main():
    n, m=[int(w) for w in input().split()]
    graph=[[False for i in range(n)] for j in range(n)]
    for i in range(m):
        a, b=[int(w) for w in input().split()]
        a-=1
        b-=1
        graph[a][b]=True
        graph[b][a]=True

    res=count_path(graph, 0, set())
    print(res)

if __name__=="__main__":
    main()
