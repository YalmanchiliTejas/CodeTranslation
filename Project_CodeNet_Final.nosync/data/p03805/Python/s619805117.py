import sys
sys.setrecursionlimit(1000000)

N, M = map(int, input().split())
edge = [[] for _ in range(N + 1)]
ab = [list(map(int, input().split())) for _ in range(M)]
for i in range(M):
    a, b = ab[i][0] - 1, ab[i][1] - 1
    edge[a].append(b)
    edge[b].append(a)

ans = 0

def f(now, v):
    global ans
    v |= (1 << now)
    for to in edge[now]:
        if not (v & (1<<to)):
            f(to, v)
    if bin(v).count("1") == N:
        ans += 1

f(0, 0)

print(ans)
