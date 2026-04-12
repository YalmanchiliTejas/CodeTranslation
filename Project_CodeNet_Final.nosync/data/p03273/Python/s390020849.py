h, w = map(int, input().split())
al = list(list(input()) for _ in range(h))
row = [False] * w
col = [False] * h

for i in range(h):
    for j in range(w):
        if al[i][j] == '#':
            col[i] = True
            row[j] = True
ans = []
w_len = len(row) - row.count(False)
for i in range(h):
    tmp = ''
    if col[i]:
        for j in range(w):
            if row[j]:
                tmp += al[i][j]
        ans.append(tmp)

for a in ans:
    print(*a, sep='')