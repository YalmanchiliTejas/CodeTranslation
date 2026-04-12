import sys
from collections import deque, Counter, defaultdict
from itertools import permutations
import heapq


def resolve():
    N, M = map(int, sys.stdin.readline().strip().split())
    adj_mat = [[False] * N for _ in range(N)]
    for _ in range(M):
        a, b = tuple(map(int, sys.stdin.readline().strip().split()))
        adj_mat[a-1][b-1] = True
        adj_mat[b-1][a-1] = True
    ans = 0
    for perm in permutations(range(N)):
        if perm[0] != 0:
            break
        cur = 0
        while cur < N - 1:
            if not adj_mat[perm[cur]][perm[cur+1]]:
                break
            cur += 1
        else:
            ans += 1

    print(ans)


if __name__ == "__main__":
    resolve()
