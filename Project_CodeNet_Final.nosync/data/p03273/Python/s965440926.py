# -*- coding: utf-8 -*-

H,W = map(int, input().split())

a = []
for i in range(0,H):
    data = str(input())
    a.append(list(data))

for i in range(H-1,-1,-1):
    if '#' in a[i]:
        pass
    else:
        del a[i]

for i in range(W-1,-1,-1):
    check = 0
    for j in range(0,int(len(a))):
        if a[j][i] == "#":
            check = 1
            break
        else:
            pass
    if check == 0:
        for j in range(0,int(len(a))):
            del a[j][i]

for i in a:
    print(''.join(i))