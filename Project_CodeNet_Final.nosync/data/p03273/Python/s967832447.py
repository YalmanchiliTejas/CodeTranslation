# sys.stdin.readline()
import sys
input = sys.stdin.readline

h, w = map(int, input().split())
M = [list(input()) for _ in range(h)]#[[x,x,x], [y,y,y], ..., [z,z,z]]

#wh = '.'
bk = '#'

for i in range(h):
    flg = True
    for j in range(w):
        if M[i][j] == bk:
            flg = False
            break
    if flg:
        for j in range(w):
            M[i][j] = ''

for j in range(w):
    flg = True
    for i in range(h):
        if M[i][j] == bk:
            flg = False
            break
    if flg:
        for i in range(h):
            M[i][j] = ''     

for i in range(h):
    res = ''
    for j in range(w):
        if M[i][j] != '':
            res += M[i][j]
    if res != '':
        print(res)