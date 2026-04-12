import sys
IS = lambda: sys.stdin.readline().rstrip()
II = lambda: int(IS())
MII = lambda: list(map(int, IS().split()))
MIIZ = lambda: list(map(lambda x: x-1, MII()))

def dfs(g,e,now,ret):
    e[now] = True
    if all(e): ret += 1
    for next in g[now]:
        if e[next]: continue
        ret = dfs(g,e,next,ret)
    e[now] = False
    return ret

def main():
    n, m = MII()
    g = {i: [] for i in range(n)}
    for _ in range(m):
        x, y = MIIZ()
        g[x].append(y)
        g[y].append(x)
    ret = 0
    e = [False]*n
    e[0] = True
    ret = dfs(g,e,0,ret)
    print(ret)

if __name__ == '__main__':
    main()
