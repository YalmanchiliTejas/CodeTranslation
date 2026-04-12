import sys
sys.setrecursionlimit(10 ** 6)

n, m = list(map(int, input().split()))
data = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    data[a-1].append(b-1)
    data[b-1].append(a-1)

ans = 0


def dfs(pos, cnt, his):
    global ans
    his[pos] = 1
    if cnt == n:
        if sum(his) == n:
            ans += 1
        return

    for next in data[pos]:
        dfs(next, cnt+1, his[:])


dfs(0, 1, [0]*n)
print(ans)
