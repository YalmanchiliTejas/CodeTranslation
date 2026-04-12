h, w = map(int, input().split())
lis = []
for i in range(h):
    lis.append(input())

row = [False] * h
col = [False] * w
for i in range(h):
    for j in range(w):
        if lis[i][j] == '#':
            row[i] = True
            col[j] = True

for i in range(h):
    if row[i]:
        s = ''
        for j in range(w):
            if col[j]:
                s += lis[i][j]
        print(s)
