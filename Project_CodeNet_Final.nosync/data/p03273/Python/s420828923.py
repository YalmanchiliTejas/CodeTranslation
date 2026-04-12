import sys
input = sys.stdin.readline
H,W = [int(i) for i in input().split()]
nes = ['0'] * H
indexa = []
for i in range(H) :
    li = list(input())
    nes[i] = li
for i in range(H) :
    del nes[i][-1]
a = 0
for i in range(H) :
    for j in range(W) :
        if nes[i][j] == "#" :
            a = 1
            break
    if a == 0 and nes[i][W-1] == "." :
        indexa.append(i)
    a = 0
count = 0
for i in indexa :
    del nes[i-count]
    count+=1
length = len(nes)
indexaa = []
b = 0
for j in range(W) :
    for i in range(length) :
        if nes[i][j] == "#" :
            b = 1
            break
    if nes[length-1][j] == "." and b == 0 :
        indexaa.append(j)
    b = 0
counta = 0
for i in indexaa :
    for j in range(length) :
        del nes[j][i-counta]
    counta+=1
for i in range(length) :
    t = ''.join(nes[i])
    print(t)