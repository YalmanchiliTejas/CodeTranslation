from functools import reduce
import operator

N = int(input())
Ss = list(map(int, input().split()))
Ts = list(map(int, input().split()))
Us = list(map(int, input().split()))
Vs = list(map(int, input().split()))
mat = [[0] * N for _ in range(N)]
counts_r = [[0] * 64 for _ in range(N)]
counts_c = [[0] * 64 for _ in range(N)]


class NotOK(Exception):
    pass


try:
    for i in range(N):
        for j in range(N):
            x = 0
            if not Ss[i]:
                x |= Us[i]
            if not Ts[j]:
                x |= Vs[j]
            if Ss[i] and (~Us[i] & x):
                raise NotOK
            if Ts[j] and (~Vs[j] & x):
                raise NotOK
            if Ss[i] and Ts[j]:
                x |= Us[i] & Vs[j]
            mat[i][j] = x
            for k in range(64):
                if (x >> k) & 1:
                    counts_r[i][k] += 1
                    counts_c[j][k] += 1

    def corr(x, vals, ors, counts):
        for k in range(64):
            if (x >> k) & 1 == 0:
                continue
            for j in range(N):
                if ors[j]:
                    continue
                if counts[j][k] >= N - 1:
                    continue
                counts[j][k] += 1
                vals[j] += 1 << k
                x -= 1 << k
                if not x:
                    return x
                break
        return x

    for i in range(N):
        vals = mat[i]
        if Ss[i]:
            x = reduce(operator.or_, vals)
            if corr(Us[i] & ~x, vals, Ts, counts_c):
                raise NotOK
        vals = []
        for j in range(N):
            vals.append(mat[j][i])
        if Ts[i]:
            x = reduce(operator.or_, vals)
            if corr(Vs[i] & ~x, vals, Ss, counts_r):
                raise NotOK
            for j in range(N):
                mat[j][i] = vals[j]
    for i in range(N):
        vals = mat[i]
        if Ss[i]:
            x = reduce(operator.or_, vals)
        else:
            x = reduce(operator.and_, vals)
        if x != Us[i]:
            raise NotOK
        vals = []
        for j in range(N):
            vals.append(mat[j][i])
        if Ts[i]:
            x = reduce(operator.or_, vals)
        else:
            x = reduce(operator.and_, vals)
        if x != Vs[i]:
            raise NotOK
    for i in range(N):
        print(*mat[i])
except NotOK:
    print(-1)
