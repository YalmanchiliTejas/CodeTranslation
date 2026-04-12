import numpy as np
H, W = map(int, input().split())
a_list = []
for i in range(H):
    a_list.append(list(map(str, input().split())))
dot = '....................................................................................................'

a_list2 = []
for i in range(H):
    if a_list[i] != [dot[0:W]]:
        a_list2.append([c for c in a_list[i][0]])

a_list3 = []
for i in range(len(a_list2[0])):
    if ''.join(list(np.array(a_list2)[:,i])) != dot[0:len(a_list2)]:
        a_list3.append(list(np.array(a_list2)[:,i]))

for i in range(len(a_list3[0])):
    print(''.join(list(np.array(a_list3).T[i,:])))