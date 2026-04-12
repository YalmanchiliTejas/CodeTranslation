import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

N, M = map(int, input().split())
tLst = [[] for _ in range(N)]
vLst = [0] * N

for i in range(M):
    a, b = map(int, input().split())
    tLst[a - 1].append(b - 1)
    tLst[b - 1].append(a - 1)

def dfs(n, index, v, ans):
    vLst[index] = 1
    if n == N - 1:
        ans += 1
        return ans
    for i in tLst[index]:
        if v == i:
            continue
        elif vLst[i] == 1:
            continue
        ans = dfs(n + 1, i, index, ans)
        vLst[i] = 0
    return ans
print(dfs(0, 0, 0, 0))