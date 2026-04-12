h,w = map(int, input().split())
d = []
for i in range(h):
    d.append(input())
row = [False] * h
col = [False] * w
for i in range(h):
    for j in range(w):
        if d[i][j] == '#':
            row[i] = True
            col[j] = True
for i in range(h):
    if row[i]:
        s = ""
        for j in range(w):
            if col[j]:
                s += d[i][j]
        if len(s) > 0:
            print(s)