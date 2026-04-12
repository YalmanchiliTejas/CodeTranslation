H,W = map(int,input().split())
s = [input() for _ in range(H)]
h = []
w = []
for i in range(H):
    if '#' not in s[i]:
        h.append(i)

for i in range(W):
    ok = True
    for j in range(H):
        if s[j][i] == "#":
            ok = False
    if ok: w.append(i)
for i in range(H):
    if i in h: continue
    for j in range(W):
        if j not in w:
            print(s[i][j],end="")
    print()