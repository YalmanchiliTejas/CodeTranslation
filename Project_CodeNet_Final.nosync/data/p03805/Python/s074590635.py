import sys

def f(G, start, visited):
    cnt = 0
    n = len(G)
    visited_ = visited + [start]

    if len(visited_) == n:
        return 1

    next_node = set(G[start]) - set(visited_)
    if len(next_node) == 0:
        return 0

    for nn in next_node:
        cnt += f(G, nn, visited_)

    return cnt


def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        G[a-1].append(b-1)
        G[b-1].append(a-1)

    cnt = f(G, 0, [])

    return cnt


if __name__ == '__main__':
    print(main())
