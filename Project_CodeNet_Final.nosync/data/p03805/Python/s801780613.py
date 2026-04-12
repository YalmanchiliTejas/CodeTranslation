res = 0
def main():
    import sys
    #input = sys.stdin.readline
    sys.setrecursionlimit(10000000)
    from collections import Counter, deque
    #from collections import defaultdict
    from itertools import combinations
    #from itertools import accumulate, product, permutations
    from math import floor, ceil

    #mod = 1000000007


    N,M = map(int, input().split())
    g = [[] for _ in range(N)]
    for _ in range(M):
        a,b = map(int, input().split())
        g[a-1].append(b-1)
        g[b-1].append(a-1)

    visited = [0]*N

    def dfs(node):
        global res
        visited[node]=1
        if all(visited):
            res += 1
            return
        for n_node in g[node]:
                if not visited[n_node]:
                    dfs(n_node)
                    visited[n_node] = 0
    dfs(0)
    print(res)

if __name__ == '__main__':
    main()
