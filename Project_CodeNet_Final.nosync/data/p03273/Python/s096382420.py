# coding: utf-8


H, W = map(int,input().split())
moto = []
for i in range(H):
    moto.append(list(input()))
for i in range(H):
    j = 0
    while moto[H-i-1][j] == ".":
        if j == W-1:
            moto.pop(H-i-1)
            break
        j += 1

for i in range(W):
    j = 0
    while moto[j][W-i-1] == ".":
        if j == len(moto)-1:
            for k in range(len(moto)):
                moto[k].pop(W-i-1)
            break
        j += 1
for i in range(len(moto)):
    for j in range(len(moto[0])-1):
        print(moto[i][j],end="")
    print(moto[i][len(moto[0])-1])