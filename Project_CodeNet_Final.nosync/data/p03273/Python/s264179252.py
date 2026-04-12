BLACK = '#'
H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]
a = [x for x in a if x.count(BLACK) != 0]
H = len(a)
idx = []
for j in range(W):
    if [a[i][j] for i in range(H)].count(BLACK) == 0:
        idx.append(j)
a = [[x for j, x in enumerate(a[i]) if j not in idx] for i in range(H)]
for i in range(H):
    print(''.join(a[i]))