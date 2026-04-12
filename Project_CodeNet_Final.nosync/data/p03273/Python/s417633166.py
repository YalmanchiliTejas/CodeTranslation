import os, sys, re, math

def dorow(N):
    cnt = 0
    for i in range(1, N+1):
        if N % i == 0:
            cnt += 1
    return cnt

H,W = map(int,input().split(' '))
table = []
for h in range(H):
    tmp = input()
    if tmp != '.' * W:
        table.append(tmp)

ret = ['' for _ in range(len(table))]

for i in range(W):
    flg = False
    for j in range(len(table)):
        if table[j][i] == '#':
            flg = True
            break

    if flg:
        for j in range(len(table)):
            ret[j] += table[j][i]

for r in ret:
    print(r)
