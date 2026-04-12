import numpy as np

N = int(input())
lst = np.array(list(map(int, input().split())))

cnt = 1
flag = True
for i in range(1, N):
    mount = lst[i]
    flag = True
    for j in range(0, i):
        if lst[j] > mount:
            flag = False
            break
    if flag == True:
        cnt = cnt + 1
print(cnt)