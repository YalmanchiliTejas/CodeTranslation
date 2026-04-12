import sys
import itertools
import math
input = sys.stdin.readline
#sys.setrecursionlimit(1e9)
N,M = map(int,input().split())

ab = [list(map(int,input().split())) for _ in range(M)]

graph=[[0]*8 for _ in range(8)]
def dfs(v,visited):
    if sum(visited) == N:
        return 1
    ret =0
    for i in range(N):
        if graph[v][i] == 1 and visited[i] == 0:
            visited[i]=1
            ret += dfs(i,visited)
            visited[i]=0
    return ret
def main():
    """code here"""

    for i in range(M):
        a=ab[i][0]
        b=ab[i][1]
        graph[a-1][b-1]=1
        graph[b-1][a-1]=1

    visited=[0]*N
    visited[0]=1
    print(dfs(0,visited))
    
if __name__ == '__main__':
    main()