def bfs(n, node, prev, visited, graph):
    visited.append(node)
    if len(visited) == n:
        return 1

    res = 0
    for edge in graph[node]:
        if edge == prev:
            continue
        if edge in visited:
            continue
        res += bfs(n, edge, node, visited[:], graph)
    # print(visited)
    return res


def main():
    n, m = map(int, input().split())
    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        i, j = map(int, input().split())
        graph[i].append(j)
        graph[j].append(i)

    ans = bfs(n, 1, 0, [], graph)
    print(ans)


if __name__ == "__main__":
    main()
