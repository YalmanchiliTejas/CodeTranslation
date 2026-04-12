import numpy as np

h, w = map(int, input().split())

li = []
for i in range(h):
    a = list(input())
    li.append(a)

count = 0
li_2 = []
for i in range(h):
    for j in range(w):
        if li[i][j] == '#':
            li_2.append(list(li[i][:]))
            count += 1
            break
li_3 = []
li_2 = [list(x) for x in zip(*li_2)]

count2= 0
for j in range(w):
    for k in range(count):
        if li_2[j][k] == '#':
            li_3.append(li_2[j][:])
            count2 += 1
            break


li_3 = [list(y) for y in zip(*li_3)]

for i in range(count):
    for j in range(count2):
        print(li_3[i][j], end='')
        if j == count2-1:
            print('')

