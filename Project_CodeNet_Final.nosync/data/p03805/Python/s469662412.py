N, M = list(map(int, input().split()))
data = [[] for _ in range(N+1)]

for i in range(M):
    a, b = map(int, input().split())
    data[a].append(b)
    data[b].append(a)

def dfs(x, been):
    ans = 0
    if len(been) == N:
        return 1
    else:
        for i in data[x]:
            if been.count(str(i)) == 0:
                been += str(i)
                ans += dfs(i, been)
                been = been[:-1]

    return ans

been = '1'
print(dfs(1, been))
