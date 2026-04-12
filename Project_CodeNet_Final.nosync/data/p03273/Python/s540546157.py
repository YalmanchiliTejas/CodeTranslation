H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]
tmp = []
for h in range(H):
    if set(A[h]) != {'.'}:
        tmp.append(A[h])
H = len(tmp)
ans = [[] for _ in range(H)]

for w in range(W):
    if set(tmp[h][w] for h in range(H)) != {'.'}:
        for h in range(H):
            ans[h].append(tmp[h][w])

for h in range(H):
    print(''.join(map(str, ans[h])))
