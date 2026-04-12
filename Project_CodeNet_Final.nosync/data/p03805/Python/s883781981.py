N, M = map(int,input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int,input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

ans = 0
def calc(G, E, s):
    global ans
    E.append(s)
    for v in G[s]:
        if v in E:
            continue
        if len(E) == N - 1 and v not in E:
            ans += 1
            return
        calc(G, E, v)
        E.remove(v)

calc(G, [], 0)
print(ans)
