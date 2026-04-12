# -*- coding: utf-8 -*-
h, w = map(int,input().split())
a = [list(input()) for _ in range(h)]

#print(a)
i = 0
j = 0
ans = "Possible"
while i < h - 1 or j < w - 1:
    flag1 = [False for _ in range(2)]
    flag2 = [False for _ in range(2)]
    #print(i, j+1)
    #print(a)
    #print(a[i][j+1])
    if i == 0 and j == 0:
        flag2[0] = True
    if i + 1 < h and a[i + 1][j] == '#':
        flag1[0] = True
    if j + 1 < w and a[i][j + 1] == '#':
        flag1[1] = True
    if i - 1 >= 0 and a[i - 1][j] == '#':
        flag2[0] = True
    if j - 1 >= 0 and a[i][j - 1] == '#':
        flag2[1] = True
    #print(flag1, flag2)
    if len(set(flag1)) == 2 and len(set(flag2)) == 2:
        if flag1[0]:
            i += 1
        if flag1[1]:
            j += 1
    else :
        ans = "Impossible"
        break
if a[h - 2][w - 1] == '#' and a[h - 1][w - 2] == '#':
    ans = "Impossible"
print(ans)
