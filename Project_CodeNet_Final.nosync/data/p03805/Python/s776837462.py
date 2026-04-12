N, M = [int(x) for x in input().split()]

edges = []
for i in range(M):
    a, b = [int(x) for x in input().split()]
    edges.append((a, b))
    edges.append((b, a))


def f(curpath, N):
    if len(curpath) == N:
        # print(curpath)
        return 1
    ret = 0
    now = curpath[-1]

    for e in edges:
        if now == e[0] and e[1] not in curpath:
            temp = curpath[:]
            temp.append(e[1])
            ret += f(temp, N)
    return ret


print(f([1], N))
