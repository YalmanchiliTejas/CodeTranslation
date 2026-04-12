H, W = map(int, input().split())
HW_list = [list(input()) for i in range(H)]
import copy

tate = [False] * H
yoko = [False] * W

for h in range(H):
    for w in range(W):
        if HW_list[h][w] == '#':
            tate[h] = True
            yoko[w] = True

for h in range(H):
    tmp = ''
    for w in range(W):
        if tate[h] and yoko[w]:
            tmp += HW_list[h][w]
    if tmp == '':
        continue
    print(tmp)
