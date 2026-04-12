H, W = map(int, input().split())
# A = [['.']+list(input())+['.'] for i in range(H)]
A = [list(input()) for i in range(H)]
flag = True
endi = 0
for i in range(H):
    if A[i].index('#') == endi:
        for j in range(W):
            if A[i][j] == '#':
                endi = j
        continue
    flag = False
    break


if flag:
    print('Possible')
else:
    print('Impossible')

