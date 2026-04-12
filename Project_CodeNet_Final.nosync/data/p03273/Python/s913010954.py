h, w = (int(i) for i in input().split())
a = [input() for i in range(h)]
ans = []
for i in range(h):
    if '#' in a[i]:
        ans.append(a[i])

del_col_idxs = set()
for i in range(w):
    for j in range(h):
        if a[j][i] == "#":
            break
    else:
        del_col_idxs.add(i)

for i in range(len(ans)):
    for j in range(w):
        if not j in del_col_idxs:
            print(ans[i][j],sep="",end="")
    print()