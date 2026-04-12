H, W = map(int, input().split())
a = [input() for _ in range(H)]

del_h = []
del_w = []

for i, h in enumerate(a):
    if "#" not in h:
        del_h.append(i)
for j in range(W):
    judge = True
    for k in range(H):
        if a[k][j] == "#":
            judge = False
    if judge:
        del_w.append(j)
for i in range(H):
    ans = ""
    for j in range(W):
        if i in del_h or j in del_w:
            pass
        else:
            ans += a[i][j]
    if len(ans) > 0:    
        print(ans)