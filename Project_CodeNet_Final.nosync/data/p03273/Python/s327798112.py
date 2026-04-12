h, w = map(int, input().split())
al = list(list(input()) for _ in range(h))
row = [0]*w
col = [0]*h

for i in range(h):
    for j in range(w):
        if al[i][j] == '#':
            col[i] += 1
            row[j] += 1
ans = []
w_len = len(row) - row.count(0)
for i in range(h):
    tmp = ''
    if col[i] != 0:
        for j in range(w):
            if row[j] != 0:
                tmp += al[i][j]
        ans.append(tmp)

for a in ans:
    print(*a, sep='')