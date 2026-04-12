import itertools


def main():
    N, M = map(int, input().split())
    node_lst = [x for x in range(N)]
    edge_lst = [list(map(int, input().split())) for _ in range(M)]
    ans = 0

    for route in itertools.permutations(node_lst):
        is_visited = [False] * N
        is_visited[0] = True
        if route[0] != 0:
            continue

        for i in range(N - 1):
            if [route[i] + 1, route[i + 1] + 1] in edge_lst and is_visited[route[i + 1]] == False:
                is_visited[route[i + 1]] = True
            if [route[i + 1] + 1, route[i] + 1] in edge_lst and is_visited[route[i + 1]] == False:
                is_visited[route[i + 1]] = True

        if is_visited == [True] * N:
            ans += 1

    print(ans)


if __name__ == "__main__":
    main()
