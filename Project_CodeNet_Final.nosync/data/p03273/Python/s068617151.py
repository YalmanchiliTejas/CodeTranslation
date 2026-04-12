H,W = list(map(int,input().split(" ")))
a = [list(input()) for i in range(H)]
h = []
w = []
for i in range(0,H):
    if "#" not in a[i]:
        h+=[(i,j,) for j in range(W)]

for i in range(W):
    for j in range(H):
        if a[j][i] != ".":
            break
        else:
            w.append(i)
    if w.count(i) == H:
        h+=[(k,i) for k in range(H)]
r = []
for i in range(H):
    c =[]
    for j in range(W):
        if (i,j,) in h:
            continue
        else:
            c.append(a[i][j])
    r.append(c)
for i in r:
    if i != []:
        print("".join(i))
