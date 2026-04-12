import sys
input = sys.stdin.readline
H,W = [int(i) for i in input().split()]
nes = ['0'] * H
for i in range(H) :
    li = list(input())
    nes[i] = li
yoko = [False] * H
tate = [False] * W
for i in range(H) :
    for j in range(W) :
        if nes[i][j] == "#" :
            yoko[i] = True
            tate[j] = True
for i in range(H) :
    if yoko[i] :
        for j in range(W) :
            if tate[j] :
                print(nes[i][j],end = '')
        print()