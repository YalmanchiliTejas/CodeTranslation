import sys
sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))
def resolve():
    N = ir()
    S = lr()
    T = lr()
    U = lr()
    V = lr()
    # d = [[-1]*N for i in range(N)]
    # def flip():
    #     for i in range(N):
    #         for j in range(i):
    #             d[i][j], d[j][i] = d[j][i], d[i][j]
    a = [[0]*N for i in range(N)]
    for k in range(64):
        val = [[bool(U[i]&(1<<k)), bool(V[i]&(1<<k))] for i in range(N)]
        d = [[-1]*N for i in range(N)]
        # for b in range(2):
        for i in range(N):
            x = val[i][0]
            if S[i] != x:
                for j in range(N):
                    if d[i][j] != x and d[i][j] != -1:
                        print(-1)
                        return
                    d[i][j] = x
        for j in range(N):
            x = val[j][1]
            if T[j] != x:
                for i in range(N):
                    if d[i][j] != x and d[i][j] != -1:
                        print(-1)
                        return
                    d[i][j] = x
            # flip()
        for _ in range(2):
            # for b in range(2):
            for i in range(N):
                x = val[i][0]
                if S[i] == x:
                    p = []
                    ok = False
                    for j in range(N):
                        if d[i][j] == -1:
                            p.append(j)
                        if d[i][j] == x:
                            ok = True
                    if ok:
                        continue
                    if len(p) == 0:
                        print(-1)
                        return
                    if len(p) == 1:
                        d[i][p[0]] = x
            for j in range(N):
                x = val[j][1]
                if T[j] == x:
                    p = []
                    ok = False
                    for i in range(N):
                        if d[i][j] == -1:
                            p.append(i)
                        if d[i][j] == x:
                            ok = True
                    if ok:
                        continue
                    if len(p) == 0:
                        print(-1)
                        return
                    if len(p) == 1:
                        d[p[0]][j] = x
                # flip()
        ni = []
        nj = []
        for i in range(N):
            filled = True
            for j in range(N):
                if d[i][j] == -1:
                    filled = False
                    break
            if not filled:
                ni.append(i)
        for j in range(N):
            filled = True
            for i in range(N):
                if d[i][j] == -1:
                    filled = False
                    break
            if not filled:
                nj.append(j)
        for i, ii in enumerate(ni):
            for j, jj in enumerate(nj):
                d[ii][jj] = (i+j)%2
        for i in range(N):
            for j in range(N):
                a[i][j] |= d[i][j]<<k
    for i in range(N):
        print(*a[i], sep=' ')
resolve()