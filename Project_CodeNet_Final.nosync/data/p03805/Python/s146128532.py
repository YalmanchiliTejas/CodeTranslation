from collections import defaultdict, deque

def main():
    n, m = map(int, input().split())
    edges = defaultdict(list)

    for _ in range(m):
        a, b = [int(s) - 1 for s in input().split()]
        edges[a].append(b)
        edges[b].append(a)
    
    visited = 1
    pos = 0
    mask = (1 << n) - 1
    print(solve(edges, pos, visited, mask))
    
def solve(edges, pos, visited, mask):
    if visited == mask:
        return 1

    s = 0
    for e in edges[pos]:
        if ((1 << e) & visited) == 0:
            s += solve(edges, e, visited | (1 << e), mask)
    
    return s

main()
