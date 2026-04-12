# -*- coding: utf-8 -*-
h, w = map(int,input().split()) 
a = []
for i in range(h):
    a.append(list(str(input())))

tmp = [[0 for _ in range(w)] for _ in range(h)] 
for i in range(h):
    for j in range(w):
        if a[i][j] == '.':
            tmp[i][j] = 0
        else:
            tmp[i][j] = 1

memo = []
for i in range(h):
    if sum(tmp[i]) == 0:
        memo.append(i)
memo2 = []
for i in range(w):
    sum_tmp = 0
    for j in range(h):
        sum_tmp += tmp[j][i]
    if sum_tmp == 0:
        memo2.append(i)

for i in range(h):
    if not i in memo:
        for j in range(w):
            if not j in memo2:
                print(a[i][j], end = '')
        print('')
