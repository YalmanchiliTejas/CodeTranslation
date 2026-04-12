import sys

h, w = map(int, input().split())
a_list = []

for i in range(h):
    tmp = input()
    if '#' in tmp:
        a_list.append(list(tmp))

del_list = []

for i in range(w):
    tmp = ''
    for j in a_list:
        tmp += j[i]
    if not '#' in tmp:
        del_list.append(i)

for i in del_list[::-1]:
    for j in range(len(a_list)):
        a_list[j].pop(i)

for i in a_list:
    print(''.join(i))
