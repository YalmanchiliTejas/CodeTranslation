def t(A):
    ret = []
    for i in range(len(A[0])):
        r = []
        for j in range(len(A)):
            r.append(A[j][i])
        ret.append("".join(r))
    return ret

def d(A):
    ret = []
    for r in A:
        if r.count("#") > 0:
            ret.append(r)
    return ret

H, W = map(int, input().split())
A = [input() for _ in range(H)]

A = t(d(A))
A = t(d(A))
for r in A:
    print(r)
