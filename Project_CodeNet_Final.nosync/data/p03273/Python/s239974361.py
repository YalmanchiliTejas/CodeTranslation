h,w = map(int, input().split())
A = [input() for _ in range(h)]

dh = []
for l in A:
    if l[0] == '.' and len(set(l)) == 1:
        continue
    dh.append(l)

wj = []
for j in range(w):
    for i in range(len(dh)):
        if dh[i][j] == '#':
            wj.append(j)
            break

ans = ['' for _ in range(len(dh))]
for i in range(len(ans)):
    for j in wj:
        ans[i] += dh[i][j]
print('\n'.join(ans))
