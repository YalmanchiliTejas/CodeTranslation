import sys
input = sys.stdin.readline

import copy

H,W = map(int,input().split())
a = [list(input().split()) for _ in range(H)]
for i in range(H):
    a[i] = list(a[i][0])
a_copy = copy.copy(a)
ans = [[] for _ in range(H)]
h=0
for i in range(H):
    Flag = True
    for j in range(W):
        if a[i][j] != ".":
            Flag = False
            break
    if not(Flag):
        for j in range(W):
            ans[h].append(a[i][j])
        h+=1
ans_H=h

ans2 = [[] for _ in range(H)]

for i in range(W):
    Flag = True
    for j in range(ans_H):
        if ans[j][i] != ".":
            Flag = False
            break
    if not(Flag):
        for j in range(ans_H):
            ans2[j].append(ans[j][i])


for i in range(ans_H):
    print("".join(ans2[i]))



