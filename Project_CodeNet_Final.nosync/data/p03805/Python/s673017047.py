N,M = map(int,input().split())
if M == 0:
    print(0)
else:
    l = [[0 for _ in range(N)] for _ in range(N)]
    for _ in range(M):
        a,b = map(int,input().split())
        l[a-1][b-1] = 1
        l[b-1][a-1] = 1
    g = 0
    def dfs(a,route):
        global g
        if len(route) == N:g += 1
        else:
            for i in range(N):
                if a == i:pass
                else:
                    if l[a][i] == 1 and (not i in route):
                        dfs(i,route+[i])
    dfs(0,[0])
print(g)