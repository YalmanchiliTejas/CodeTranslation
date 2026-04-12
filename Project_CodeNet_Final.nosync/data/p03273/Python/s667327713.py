# -*- coding: utf-8 -*-

H, W = list(map(int, input().split()))

mtrx = []

for i in range(H):
    inputstr = input()
    if '#' in inputstr:
        mtrx.append(list(inputstr))

trv_mtrx = list(map(list, zip(*mtrx)))

new_mtrx = []

for line in trv_mtrx:
    if '#' in line:
        new_mtrx.append(line)

for l in list(map(list,zip(*new_mtrx))):
    print(''.join(l))