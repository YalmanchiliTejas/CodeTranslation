#! /usr/bin/env python3

import sys
from collections import deque
int1 = lambda x: int(x) - 1
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(500000)


# adjacent_2
def adjacent_2(h, w, H, W):
    ret = []
    for (dh, dw) in [(0, 1), (1, 0)]:
        h_ = h + dh
        w_ = w + dw
        if (0 <= h_) & (h_ < H) & (0 <= w_) & (w_ < W):
            ret.append((h_, w_))
    return ret


def adjacent_2_(h, w, H, W):
    ret = []
    for (dh, dw) in [(0, -1), (-1, 0)]:
        h_ = h + dh
        w_ = w + dw
        if (0 <= h_) & (h_ < H) & (0 <= w_) & (w_ < W):
            ret.append((h_, w_))
    return ret


H, W = map(int, readline().split())
M = [list(readline().decode().rstrip()) for _ in range(H)]

que = deque([(0, 0)])
while len(que) != 0:
    acc = que.popleft()

    ret = adjacent_2(*acc, H, W)
    cnt = adjacent_2_(*acc, H, W)
    ret = [pos for pos in ret if M[pos[0]][pos[1]] == '#']
    cnt = [pos for pos in cnt if M[pos[0]][pos[1]] == '#']

    if (len(cnt) > 1):
        print("Impossible")
        sys.exit()
    if acc == (H - 1, W - 1):
        break

    if (len(ret) != 1) or (len(cnt) > 1):
        print("Impossible")
        sys.exit()
    que.append(*ret)

print("Possible")
