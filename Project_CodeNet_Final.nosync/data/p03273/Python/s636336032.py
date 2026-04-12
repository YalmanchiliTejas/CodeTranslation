import numpy as np 
H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]

for i in range(H):
    for j in range(W):
        if a[i][j] == '#':
            a[i][j] = 1
        else:
            a[i][j] = 0

a = np.array(a)

while True:
    flag = True
    for i in range(len(a)-1, -1, -1):
        if sum(a[i]) == 0:
            a = np.delete(a, i, 0)
            flag = False

    a = a.T
    for i in range(len(a)-1, -1, -1):
        if sum(a[i]) == 0:
            a = np.delete(a, i, 0)
            flag = False
    a = a.T

    if flag:
        break

ans = [['#']*len(a[0]) for _ in range(len(a))]
for i in range(len(a)):
    for j in range(len(a[i])):
        if a[i][j] == 0:
            ans[i][j] = '.'

for i in range(len(a)):
    for j in range(len(a[i])):
        print(ans[i][j], end="")
    print()
