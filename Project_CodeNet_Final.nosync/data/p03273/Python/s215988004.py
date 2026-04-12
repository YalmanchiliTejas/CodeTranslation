# -*- coding: utf-8 -*-
H, W = map(int, input().split())
aij = []

for i in range(H):
    aij.append( list(input()) )

# print(aij)

ans = []
for i in range(H):
    if aij[i] == ['.']*W:
        continue
    else:
        ans.append(aij[i])

pop_num = []
for j in range(W):
    tmp = []
    for i in range(len(ans)):
        tmp.append(ans[i][j])
    if tmp == ['.']*len(ans):
        for i in range(len(ans)):
            pop_num.append(j)

ans2 = []
for i in range(len(ans)):
    tmp = []
    for j in range(W):
        if j not in pop_num:
            tmp.append(ans[i][j])
    ans2.append(tmp)

for i in range(len(ans2)):
    print( ''.join(ans2[i]) )
