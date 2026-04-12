import sys
from collections import deque

import numpy as np

input = sys.stdin.readline


def bfs(H, W, maze, dist, sh, sw):
    queue = deque([[sh, sw]])
    dist[sh][sw] = 0
    while queue:
        h, w = queue.popleft()
        for i, j in [(1, 0), (0, 1)]:
            next_h, next_w = h + i, w + j
            if not ((0 <= next_h <= H - 1) and (0 <= next_w <= W - 1)):
                continue
            if maze[next_h][next_w] and (dist[next_h][next_w] == -1):
                dist[next_h][next_w] = dist[h][w] + 1
                queue.append([next_h, next_w])


def main():
    H, W = map(int, input().split())
    A = np.full((H, W), False, dtype=bool)
    for i in range(H):
        A[i] = [True if s == "#" else False for s in input().rstrip()]

    n_path = np.sum(A) - 1
    dist = [[-1] * W for _ in range(H)]
    bfs(H, W, A, dist, 0, 0)

    if dist[H-1][W-1] == n_path:
        print("Possible")
    else:
        print("Impossible")


if __name__ == "__main__":
    main()
