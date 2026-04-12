H,W = map(int,input().split())
a = [list(input()) for i in range(H)]
ver = []
hor = []
for j in range(W):
    tmp = []
    for i in range(H):
        tmp.append(a[i][j])
    if tmp == ["."]*H:
        ver.append(j)
for i in range(H):
    if a[i] == ["."]*W:
        hor.append(i)
ver = list(set(list(range(W)))-set(ver))
hor = list(set(list(range(H)))-set(hor))
ans = []
for i in hor:
    tmp = []
    for j in ver:
        tmp.append(a[i][j])
    ans.append(tmp)
for i in range(len(ans)):
    print("".join(ans[i]))