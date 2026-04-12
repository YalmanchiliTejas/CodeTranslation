def main():
    N,M = map(int, raw_input().split())
    conf = [[0 for i in range(N)]for j in range(N)] 
    visit = [0]*N
    c = 0
    for i in range(M):
        s,g = map(int , raw_input().split())
        conf[s-1][g-1] = 1
        conf[g-1][s-1] = 1
    visit[0] = 1
    return dfs(conf, visit, 0, c)

def dfs(conf, visit, s, c):
    if 0 not in visit:
        visit[s] = 0
        c += 1
        return c
    for i in xrange(len(visit)):
        if conf[s][i] == 1 and visit[i] == 0:
            visit[i] = 1
            c = dfs(conf, visit , i, c)
            visit[i] = 0
    return c
print main()