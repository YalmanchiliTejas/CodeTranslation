from sys import stdin

ans = 0


def dfs(cnt, current, path):
    if cnt == N:
        global ans
        ans += 1
        # print(cnt, current, path)
        return
    for i in range(N):
        # print(path)
        if s[current-1][i] == 1 and i+1 not in path:
            # print(i)
            # global path
            path.append(i+1)
            dfs(cnt+1, i+1, path)
            for i in range(cnt, len(path)):
                path.pop()


N, M = [int(x) for x in stdin.readline().rstrip().split()]
s = [[0 for i in range(N)] for j in range(N)]
cnt = 1
for i in range(M):
    a, b = [int(x) for x in stdin.readline().rstrip().split()]
    s[a-1][b-1] = 1
    s[b-1][a-1] = 1
path = [1]
dfs(cnt, 1, path)
# print(s)
print(ans)
