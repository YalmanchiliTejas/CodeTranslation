H,W = [int(x) for x in input().split()]
a = []
H2 = 0
W2 = 0
count = [0] * W
for i in range(H):
    l = list(input())
    if l != ["."]*W:
        a.append(l)
        H2 += 1
for i in range(W):
    flag = 1
    for j in range(H2):
        if a[j][i] != ".":
            flag = 0
            break
    count[i] = flag
for i in range(H2):
    an = []
    for j in range(W):
        if count[j] == 0:
            an.append(a[i][j])
    print("".join(an))

