import sys
from collections import deque

def solve():
    input = sys.stdin.readline
    H, W = map(int, input().split())
    A = [input().strip("\n") for _ in range(H)]
    q = deque()
    q.append((0, 0))
    visited = [[False] * W for _ in range(H)]
    possible = True
    while q:
        nh, nw = q.popleft()
        if not visited[nh][nw]:
            visited[nh][nw] = True
            count = 0
            if 0 <= nh + 1 < H and A[nh + 1][nw] == "#":
                if 0 <= nw - 1 and A[nh+1][nw-1] == "#":
                    possible = False
                    break
                q.append((nh+1, nw))
                count += 1
            if 0 <= nw + 1 < W and A[nh][nw+1] == "#":
                if 0 <= nh - 1 and A[nh-1][nw+1] == "#":
                    possible = False
                    break
                q.append((nh, nw+1))
                count += 1
            if count == 2:
                possible = False
                break
    else:
        if not visited[H-1][W-1]: possible = False
    print("Possible" if possible else "Impossible")

    return 0

if __name__ =="__main__":
    solve()