import sys
import os
import math

ii = lambda: int(sys.stdin.buffer.readline().rstrip())
il = lambda: list(map(int, sys.stdin.buffer.readline().split()))
fl = lambda: list(map(float, sys.stdin.buffer.readline().split()))
iln = lambda n: [int(sys.stdin.buffer.readline().rstrip()) for _ in range(n)]

iss = lambda: sys.stdin.buffer.readline().decode().rstrip()
sl = lambda: list(map(str, sys.stdin.buffer.readline().decode().split()))
isn = lambda n: [sys.stdin.buffer.readline().decode().rstrip() for _ in range(n)]

MOD = 10 ** 9 + 7


def dfs(graph, edgs, now, ret):
    edgs[now] = True
    if all(edgs): ret += 1

    for next in graph[now]:
        if edgs[next]: continue
        ret = dfs(graph, edgs, next, ret)
    edgs[now] = False
    return ret


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    N, M = il()
    g = {n: [] for n in range(N)}
    for m in range(M):
        a, b = il()
        g[a - 1].append(b - 1)
        g[b - 1].append(a - 1)

    ret = 0
    edgs = [False] * N
    edgs[0] = True
    ret = dfs(g, edgs, 0, ret)
    print(ret)


if __name__ == '__main__':
    main()
