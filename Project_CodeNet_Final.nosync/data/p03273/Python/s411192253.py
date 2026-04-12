h, w = map(int, input().split())
ls = [input().strip() for _ in range(h)]
ls = [l for l in ls if l.count('.') < w]


def transpose(ls):
    res = []
    h = len(ls)
    w = len(ls[0])
    for j in range(w):
        l = ''
        for i in range(h):
            l += ls[i][j]
        res.append(l)
    return res


h = len(ls)
ls = transpose([l for l in transpose(ls) if l.count('.') < h])

print(*ls, sep='\n')