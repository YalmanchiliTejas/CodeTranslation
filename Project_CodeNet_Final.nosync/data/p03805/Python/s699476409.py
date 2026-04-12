def main():
    import sys
    from itertools import permutations
    # readline = sys.stdin.buffer.readline
    readlines = sys.stdin.readlines
    N, M = map(int, input().split())
    edge = [[0] * N for _ in range(N)]
    for s in readlines():
        a, b = map(int, s.split())
        a -= 1; b -= 1
        edge[a][b] = 1
        edge[b][a] = 1

    cnt = 0
    for path in permutations(range(1, N)):
        path = [0] + list(path)
        for i in range(N - 1):
            v = path[i]
            nv = path[i + 1]
            if edge[v][nv] == 0:
                break
        else:
            cnt += 1
    print(cnt)


if __name__ == "__main__":
    main()
