H, W = map(int, input().split())

LL = []
for i in range(H):
    L = input()
    LL.append(L)

ans_H = []
for i in range(H):
    if "#" in LL[i]:
        ans_H.append(i)

ans_W = []
for i in range(W):
    cnt = 0
    for j in range(H):
        if LL[j][i] == "#":
            cnt = 1
    if cnt == 1:
        ans_W.append(i)


for i in ans_H:
    for j in ans_W:
        print(LL[i][j], end = "")
    print()