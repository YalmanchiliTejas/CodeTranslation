H, W = map(int, input().split())
a = []
for i in range(H):
    a.append(input())

allwhiteh = [1] * H
allwhitev = [1] * W
for i in range(H):
    for j in range(W):
        if a[i][j] == '#':
            allwhiteh[i] = 0
            allwhitev[j] = 0

for i in range(H):
    for j in range(W):
        if not allwhiteh[i] and not allwhitev[j]:
            print(a[i][j], end="")
    if not allwhiteh[i]:
        print("")


