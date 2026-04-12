'''
頂点1から全頂点通る一筆書きが何個あるか
頂点数(N)は最大で8なので道順を全列挙して調べてもいける
'''
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

    res = []
    visited = [0]*N

    def dfs(node):
        visited[node]=1
        if sum(visited)==N:
            res.append(1)
            return
        for n_node in g[node]:
                if not visited[n_node]:
                    dfs(n_node)
                    visited[n_node] = 0
    dfs(0)
    print(len(res))


    # My
    # n,m = map(int, input().split())
    # edge = [list(map(int, input().split())) for _ in range(m)]
    # res = []
    # visited = [0]*n

    # def dfs(node):
    #     visited[node-1]=1
    #     if sum(visited)==n:
    #         res.append(1)
    #         return
    #     for x,y in edge:
    #         if x == node:
    #             if not visited[y-1]:
    #                 dfs(y)
    #                 visited[y-1] = 0
    #         if y == node:
    #             if not visited[x-1]:
    #                 dfs(x)
    #                 visited[x-1] = 0

    # for a,b in edge:
    #     if a==1:
    #         dfs(a)
    #         print(len(res))
    #         exit()
    #     if b==1:
    #         dfs(b)
    #         print(len(res))
    #         exit()

if __name__ == '__main__':
    main()