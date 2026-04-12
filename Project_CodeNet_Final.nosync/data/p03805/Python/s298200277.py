N, M = map(int, input().split())
graph = [[] for _ in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

def dfs(i, visited):
    if all(visited):
        return 1
    total = 0
    for j in graph[i]:
        if not visited[j]:
            nvisited = visited[:]
            nvisited[j] = True
            total += dfs(j, nvisited)
    return total

def main():
    """ main """
    visited = [False] * N
    visited[0] = True
    print(dfs(0, visited))

if __name__ == '__main__':
    main()
