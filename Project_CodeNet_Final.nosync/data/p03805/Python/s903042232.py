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

    n,m = map(int, input().split())
    edge = [list(map(int, input().split())) for _ in range(m)]
    res = []
    visited = [0]*n

    def dfs(node):
        visited[node-1]=1
        if sum(visited)==n:
            res.append(1)
            return
        for x,y in edge:
            if x == node:
                if not visited[y-1]:
                    dfs(y)
                    visited[y-1] = 0
            if y == node:
                if not visited[x-1]:
                    dfs(x)
                    visited[x-1] = 0

    for a,b in edge:
        if a==1:
            dfs(a)
            print(len(res))
            exit()

if __name__ == '__main__':
    main()