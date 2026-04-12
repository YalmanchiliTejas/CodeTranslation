from typing import List, Tuple


def main():
    n, m = map(int, input().split())
    g = []
    for _ in range(m):
        a, b = map(int, input().split())
        g.append((a, b))
    print(osp(n, g))


def osp(n: int, g: List[Tuple[int, int]]) -> int:
    graph = [[False] * n for _ in range(n)]
    for a, b in g:
        graph[a - 1][b - 1] = True
        graph[b - 1][a - 1] = True
    v = [False] * n

    return dfs(0, v, n, graph)


def dfs(i, v, n, graph):
    v[i] = True
    if all(v):
        v[i] = False
        return 1

    cnt = 0
    for j in range(n):
        if v[j]:
            continue
        if not graph[i][j]:
            continue
        cnt += dfs(j, v, n, graph)

    v[i] = False
    return cnt


if __name__ == '__main__':
    main()
