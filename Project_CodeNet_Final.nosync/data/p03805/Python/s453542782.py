import sys
import copy

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline

in_n = lambda: int(readline())
in_nn = lambda: map(int, readline().split())
in_nl = lambda: list(map(int, readline().split()))
in_na = lambda: map(int, read().split())
in_s = lambda: readline().rstrip().decode('utf-8')

sys.setrecursionlimit(1000000)


ans = 0


def bfs(N, edge, v, search):

    search |= {v}

    global ans
    if len(search) == N:
        ans += 1
        return

    for e in edge[v]:
        if e not in search:
            bfs(N, edge, e, copy.copy(search))


def main():

    N, M = in_nn()

    edge = [[] for _ in range(N)]

    for i in range(M):
        a, b = in_nn()
        a, b = a - 1, b - 1
        edge[a].append(b)
        edge[b].append(a)

    bfs(N, edge, 0, set())

    print(ans)


if __name__ == '__main__':
    main()
