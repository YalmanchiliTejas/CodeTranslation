H, W = map(int,input().split())
a = []
for i in range(H):
    L = list(input())
    a.append(L)
delH,delW = [],[]
for i in range(H):
    if all(a[i][j]=='.' for j in range(W)):
        delH.append(i)
for j in range(W):
    if all(a[i][j]=='.' for i in range(H)):
        delW.append(j)
for i in range(H):
    for j in range(W):
        if i not in delH and j not in delW:
            print(a[i][j], end="")
    if i not in delH:
        print()
