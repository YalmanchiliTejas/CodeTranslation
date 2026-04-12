import sys
from itertools import permutations

def solve():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    Edge = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        Edge[a-1].append(b-1)
        Edge[b-1].append(a-1)

    count = 0
    for s in permutations(range(N), N):
        Visited = [False for _ in range(N)]
        for i, n in enumerate(s):
            if i == 0:
                if n != 0: break
                else: Visited[0] = True
            else:
                if n in Edge[s[i-1]]: Visited[n] = True
                else: break
        else: count += 1
    print(count)

    return 0

if __name__ == "__main__":
    solve()