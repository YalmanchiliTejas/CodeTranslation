h, w = map(int, input().split())
a = [["" for _ in range(w)] for _ in range(h)]
for y in range(h):
    s = input()
    for x in range(w):
        a[y][x] = s[x]
igny = [False] * h
ignx = [False] * w

def YYY(i, j):
    if j == h - 1:
        return a[j][i] == "."
    else:
        if YYY(i, j + 1):
            return a[j][i] == "."
    return False

def XXX(i, j):
    if i == w - 1:
        return a[j][i] == "."
    else:
        if XXX(i + 1, j):
            return a[j][i] == "."
    return False

for x in range(w):
    ignx[x] = YYY(x, 0)

for y in range(h):
    igny[y] = XXX(0, y)

for y in range(h):
    if igny[y] == False:
        for x in range(w):
            if ignx[x] == False:
                print(a[y][x], end = "")
        print()
