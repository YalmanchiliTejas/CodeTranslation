import os

import sys
import numpy as np

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7
# MOD = 998244353


N = int(sys.stdin.buffer.readline())
row_or = list(map(int, sys.stdin.buffer.readline().split()))
col_or = list(map(int, sys.stdin.buffer.readline().split()))
right = list(map(int, sys.stdin.buffer.readline().split()))
down = list(map(int, sys.stdin.buffer.readline().split()))

row_or = np.array(row_or, dtype=bool)
row_and = ~row_or
col_or = np.array(col_or, dtype=bool)
col_and = ~col_or
right = np.array(right, dtype='uint64')
down = np.array(down, dtype='uint64')


def solve(right, down):
    ret = np.full((N, N), 7, dtype='uint64')
    yet_rows = []
    yet_cols = []
    used = [False] * 2
    for r in range(N):
        if row_or[r] and right[r] == 0:
            ret[r, :] = 0
            used[0] = True
        elif row_and[r] and right[r] == 1:
            ret[r, :] = 1
            used[1] = True
        else:
            yet_rows.append(r)
    for c in range(N):
        if col_or[c] and down[c] == 0:
            ret[:, c] = 0
            used[0] = True
        elif col_and[c] and down[c] == 1:
            ret[:, c] = 1
            used[1] = True
        else:
            yet_cols.append(c)

    if len(yet_cols) == 1:
        c = yet_cols[0]
        if not used[0]:
            # 0 を優先的に使いたい
            ret[yet_rows, c] = 0
            if down[c] == 1:
                for r in yet_rows:
                    # and で 0 のところは 0 じゃないといけないので、
                    # それ以外のところを 1 つ 1 にする
                    if row_or[r] and right[r] == 1:
                        ret[r, c] = 1
                        break
        elif not used[1]:
            # 1 を優先的に使いたい
            ret[yet_rows, c] = 1
            if down[c] == 0:
                for r in yet_rows:
                    # or で 1 のところは 1 じゃないといけないので、
                    # それ以外のところを 1 つ 0 にする
                    if row_and[r] and right[r] == 0:
                        ret[r, c] = 0
                        break
        else:
            # どっちでもいい
            ret[yet_rows, c] = np.arange(len(yet_rows), dtype=int) % 2
    elif len(yet_rows) == 1:
        r = yet_rows[0]
        if not used[0]:
            # 0 を優先的に使いたい
            ret[r, yet_cols] = 0
            if right[r] == 1:
                for c in yet_cols:
                    # and で 0 のところは 0 じゃないといけないので、
                    # それ以外のところを 1 つ 1 にする
                    if col_or[c] and down[c] == 1:
                        ret[r, c] = 1
                        break
        elif not used[1]:
            # 1 を優先的に使いたい
            ret[r, yet_cols] = 1
            if right[r] == 0:
                for c in yet_cols:
                    # or で 1 のところは 1 じゃないといけないので、
                    # それ以外のところを 1 つ 0 にする
                    if col_and[c] and down[c] == 0:
                        ret[r, c] = 0
                        break
        else:
            # どっちでもいい
            ret[r, yet_cols] = np.arange(len(yet_cols), dtype=int) % 2
    else:
        # 行列両方 2 つ以上ある
        for i, r in enumerate(yet_rows):
            ret[r, yet_cols] = (np.arange(len(yet_cols), dtype=int) + i) % 2

    # つくった
    ok = True
    for r in range(N):
        if row_and[r]:
            if right[r] == 1:
                ok &= np.all(ret[r, :] == 1)
            else:
                ok &= np.any(ret[r, :] == 0)
        else:
            if right[r] == 1:
                ok &= np.any(ret[r, :] == 1)
            else:
                ok &= np.all(ret[r, :] == 0)
    for c in range(N):
        if col_and[c]:
            if down[c] == 1:
                ok &= np.all(ret[:, c] == 1)
            else:
                ok &= np.any(ret[:, c] == 0)
        else:
            if down[c] == 1:
                ok &= np.any(ret[:, c] == 1)
            else:
                ok &= np.all(ret[:, c] == 0)
    assert np.all(ret <= 1)
    return ret & 1, ok


ans = np.zeros((N, N), dtype='uint64')
for i in range(64):
    bits, ok = solve(right >> i & 1, down >> i & 1)
    if not ok:
        print(-1)
        exit()
    ans |= bits << i

for row in ans:
    print(*row)
