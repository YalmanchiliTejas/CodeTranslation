H,W = map(int,input().split())
a = []
for i in range(H):
    a.append(input().split())
g = []
r = []
for i in range(H):
    for j in range(W):
        if a[i][0][j] == "#":
            g.append(i)
            break
#print(g)
for i in range(W):
    for j in range(H):
        if a[j][0][i] == "#":
            r.append(i)
            break
#print(r)
ans = ""
for i in g:
    for j in r:
        ans += a[i][0][j]
    print(ans)
    ans = ""