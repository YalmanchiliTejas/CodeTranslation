H,W = map(int,input().split())
src = [input() for i in range(H)]

del_r = []
for i in range(H):
    if all([c=='.' for c in src[i]]):
        del_r.append(i)

del_c = []
for i,col in enumerate(zip(*src)):
    if all([c=='.' for c in col]):
        del_c.append(i)

for i in range(H):
    if i in del_r: continue
    ans = ''
    for j in range(W):
        if j in del_c: continue
        ans += src[i][j]
    print(ans)