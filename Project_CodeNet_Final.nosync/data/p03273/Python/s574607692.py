H,W = map(int,input().split())
a = []
tmp = []
ttt = []
ans = []
annn = []
for i in range(H):
    aa = input()
    aa = list(aa)
    a.append(aa)
for i in range(H):
    for j in range(W):
        if '#' == a[i][j]:
            tmp.append(a[i])
            break
H = len(tmp)
for i in range(W):
    t = []
    for j in range(H):
        t.append(tmp[j][i])
    ttt.append(t)
for i in range(W):
    for j in range(H):
        if '#' == ttt[i][j]:
            ans.append(ttt[i])
            break
W = len(ans)
for i in range(H):
    t = []
    for j in range(W):
        t.append(ans[j][i])
    annn.append(t)
for i in range(H):
    print(''.join(annn[i]))