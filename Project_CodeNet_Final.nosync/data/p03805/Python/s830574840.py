import sys
import copy
def solve():
    sys.setrecursionlimit(100000)
    input = sys.stdin.readline
    N, M = map(int, input().split())
    adjM = [[0] * N for i in range(N)] 
    for i in range(M):
        a, b = map(int, input().split())
        adjM[a - 1][b - 1] = 1
        adjM[b - 1][a - 1] = 1

    arrived = [False] * N
    ans = dfs(0, adjM, arrived, N)
    print(ans)

def dfs(now, adjM, arrived, N):
    arrived[now] = True
    if arrived == [True] * N:
        return 1
    
    cnt = 0
    for i in range(N):
        if adjM[now][i] == 1 and not arrived[i]:
            cnt += dfs(i, adjM, copy.deepcopy(arrived), N)
    
    return cnt


if __name__ == '__main__':
    solve()
