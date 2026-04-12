import sys
def input():
    return sys.stdin.readline()[:-1]

H,W = map(int,input().split(' '))
l = [list(input()) for _ in range(H)]

white_row = [True]*H
white_col_dp = []
for i in range(H):
    for j in range(W):
        elm = l[i][j]
        if elm=='#':
            white_row[i] = False
            white_col_dp.append(j)
ANS = []
white_col_dp = set(white_col_dp)
for i in range(H):
    if not white_row[i]:
        tmp = []
        for j in range(W):
            if j in white_col_dp:
                tmp.append(l[i][j])
        ANS.append(''.join(tmp))

for i in ANS:
    print(i)