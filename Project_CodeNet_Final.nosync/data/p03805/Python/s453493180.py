import sys
input = sys.stdin.readline
from operator import itemgetter

lis = []
n = 0
m = 0
ans = 0
visited = []

def dfs(i, d, fr):
    global lis, ans, visited
    if visited[i] == 1:
        return
    if d == n - 1:
        ans += 1
        return
    for j in lis[i]:
        if j != fr:
            visited[i] = 1
            # print(i+1 , j+1)
            dfs(j, d+1, i)
            visited[i] = -1


def main():
    global lis, n, m, ans, visited
    n, m = map(int, input().strip().split())
    lis = [[] for _ in range(n)]
    visited = [-1] * n
    for _ in range(m):
        a, b = list(map(lambda x: x-1, map(int, input().strip().split())))
        lis[a].append(b)
        lis[b].append(a)
    # print("##")
    dfs(0, 0, -1)
    print(ans)

if __name__ == '__main__':
    main()
