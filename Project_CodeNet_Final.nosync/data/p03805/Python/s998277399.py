import sys
from itertools import permutations

def solve():
    N, M = map(int, input().split())
    Edge = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        Edge[a-1].append(b-1)
        Edge[b-1].append(a-1)
    count = 0
    for order in permutations(range(N)):
        if order[0] != 0: continue
        for i in range(N-1):
            if order[i+1] not in Edge[order[i]]: break
        else: count += 1
    print(count)

    return 0

if __name__ == "__main__":
    solve()