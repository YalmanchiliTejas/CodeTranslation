h, w = map(int, input().split())
a = []
for i in range(h):
    a.append(list(input()))
f = False
c = 0
for i in range(h):
    for j in range(w):
        if (a[i][j] == "#"):
            c += 1


def judge(x, y, l: set):
    global a, f
    l.add("{},{}".format(x, y))
    if (x != h - 1):
        if (a[x + 1][y] == "#") and not ("{},{}".format(x+1, y) in l):
            judge(x + 1, y, l.copy())
    if (y != w - 1):
        if (a[x][y + 1] == "#") and not ("{},{}".format(x, y+1) in l):
            judge(x, y + 1, l.copy())

    if (x == h - 1) and (y == w - 1):
        if (l.__len__() == c):
            f = True


judge(0, 0, set())

print("Possible" if f else "Impossible")
