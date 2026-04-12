n, m = map(int, input().split(' '))
graph = []
for i in range(n):
    graph.append([0] * n)
for i in range(m):
    a, b = map(int, input().split(' '))
    graph[a-1][b-1] = 1
    graph[b-1][a-1] = 1


def dfs(v,n,visited):
    all_visited = True

    for i in range(n):
        if visited[i] == False:
            all_visited = False

    if all_visited:
        return 1

    ret = 0

    for i in range(n):
        if not graph[v][i]:
            continue
        if visited[i]:
            continue
        visited[i] = 1
        ret += dfs(i,n,visited)
        visited[i] = 0

    return ret

def main():
    visited = []
    for i in range(n):
        visited.append(0)
    visited[0] =1
    print((dfs(0,n,visited)))



if __name__ == '__main__':
    main()
