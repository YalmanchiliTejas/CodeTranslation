# https://atcoder.jp/contests/abc107/tasks/abc107_b


def check(m, p):
    for i in range(len(m)):
        if m[i][p] == "#":
            return(False)
    return(True)


h, w = [int(x) for x in input().split()]
a = []
b = []
for i in range(h):
    a.append(input())
for i in a:
    if i.count("#") != 0:
        b.append(i)
r = []
for i in range(w):
    if check(b, i):
        r.append(i)
for i in range(len(b)):
    tmp = list(b[i])
    for p in r:
        tmp[p] = "*"
    print("".join(tmp).replace("*", ""))
