from collections import deque
import numpy as np


def isPossible(grid):
    v = deque([[0, 0]])

    while v:
        x, y = v.popleft()
        grid[x][y] = 0
        if grid[x][y + 1]:
            v.append([x, y + 1])
            continue
        elif grid[x + 1][y]:
            v.append([x + 1, y])
            continue

    if grid.sum() == 0:
        return True
    else:
        return False


if __name__ == "__main__":
    h, w = map(int, input().split())
    grid = [[0 if i == "." else 1 for i in input()+"."] for _ in range(h)]
    grid.append([0]*(w+1))
    grid = np.array(grid)
    if isPossible(grid):
        ans = "Possible"
    else:
        ans = "Impossible"
    print(ans)
