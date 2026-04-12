H, W = map(int, input().split())
s = [input() for _ in range(H)]

row = []
clm = []
for i in range(H):
    if '#' not in set(s[i]):
        row.append(i)
for i in range(W):
    if '#' not in set([v[i] for v in s]):
        clm.append(i)

for i in range(H):
    if i in row:
        continue
    ans = ''
    for j in range(W):
        ans += '' if j in clm else s[i][j]
    print(ans)