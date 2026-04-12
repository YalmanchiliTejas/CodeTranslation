import sys
sys.setrecursionlimit(10**9)


def search(cr_node, cr_depth, is_visited, edges, max_depth):
    if cr_node in is_visited:
        return 0
    elif cr_depth == max_depth:
        return 1
    else:
        count = 0

        if edges[cr_node]:
            is_visited.add(cr_node)
            for edge in edges[cr_node]:
                count += search(edge, cr_depth + 1,
                                is_visited, edges, max_depth)
            is_visited.remove(cr_node)

        return count


def main():
    N, M = map(int, input().split())
    edges = dict()
    for i in range(N):
        edges[i] = []

    for i in range(M):
        a, b = map(int, input().split())
        edges[a - 1].append(b - 1)
        edges[b - 1].append(a - 1)

    print(search(0, 1, set(), edges, N))


if __name__ == '__main__':
    main()
