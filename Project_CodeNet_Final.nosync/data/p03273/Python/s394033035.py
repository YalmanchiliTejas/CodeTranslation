h, w = map(int, input().split())
G = [list(input()) for _ in range(h)]

remove_h = []
for i in range(h):
    if set(G[i]) == {"."}:
        remove_h.append(i)

remove_w = []
for j in range(w):
    if set([g[j] for g in G]) == {"."}:
        remove_w.append(j)

for i in range(h):
    if i not in remove_h:
        S = ""
        for j in range(w):
            if j not in remove_w:
                S += G[i][j]
        print(S)