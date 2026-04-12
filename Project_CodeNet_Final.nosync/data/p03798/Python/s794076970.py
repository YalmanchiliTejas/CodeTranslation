import sys
N = int(input())
s = input()
r = ['SS', 'SW', 'WS', 'WW']
flag = [False, False]
for _i in range(4):
    for _j in range(1, N-1):
        if (s[_j] == 'o' and r[_i][_j] == 'S') or (s[_j] == 'x' and r[_i][_j] == 'W'):
            r[_i] += r[_i][_j-1]
        else:
            if r[_i][_j] == 'W':
                if r[_i][_j-1] == 'S':
                    r[_i] += 'W'
                else:
                    r[_i] += 'S'
            if r[_i][_j] == 'S':
                if r[_i][_j-1] == 'W':
                    r[_i] += 'S'
                else:
                    r[_i] += 'W'
    if (s[N-1] == 'o' and r[_i][N-1] == 'S') or (s[N-1] == 'x' and r[_i][N-1] == 'W'):
        if r[_i][N-2] == r[_i][0]:
            flag[0] = True
    else:
        if r[_i][N-2] != r[_i][0]:
            flag[0] = True
    if flag[0]:
            if (s[0] == 'o' and r[_i][0] == 'S') or (s[0] == 'x' and r[_i][0] == 'W'):
                if r[_i][N-1] == r[_i][1]:
                    flag[1] = True
            else:
                if r[_i][N-1] != r[_i][1]:
                    flag[1] = True
    if flag[0] and flag[1]:
        print(r[_i])
        break
    else:
        flag = [False, False]
if not(flag[0]) and not(flag[1]):
    print(-1)