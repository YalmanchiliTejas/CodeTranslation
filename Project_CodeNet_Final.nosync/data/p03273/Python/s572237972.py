H,W = map(int,input().split())
a = []
for i in range(H):
    a.append(list(input()))

rm = []

for i in range(H):
    if "#" not in a[i]:
        for j in range(W):
            rm.append([i,j])

for i in range(W):
    t = []
    for k in range(H):
        t.append(a[k][i])
    if "#" not in t:
        for j in range(H):
            rm.append([j,i])


aa = []
for i in range(H):
    t = []
    for j in range(W):
        if [i,j] not in rm:
            t.append(a[i][j])
    if len(t) != 0 :
        aa.append(t)


for i in range(len(aa)):
    for j in range(len(aa[i])):
        print(aa[i][j],end="")
    print("")
