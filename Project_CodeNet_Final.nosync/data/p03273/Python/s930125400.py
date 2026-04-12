# -*- coding: utf-8 -*-
"""
Created on Wed Jul 18 00:01:41 2018

@author: Yuya
"""

n, m=map(int, input().split())

ans = []
c = 0

for i in range(n):
    tmp=list(input())
    f = 1
    for j in range(m):
        if tmp[j]=="#":
            f = -1
    if f<0:
        ans.append(tmp)
        c+=1


ans2 = [["0" for i in range(c)] for j in range(m)]

for i in range(m):
    for j in range(c):
        ans2[i][j] = ans[j][i]


d = m

for i in range(m-1, -1, -1):
    f = 1
    for j in range(c):
        if ans2[i][j]=="#":
            f = -1
    if f>0:
        del ans2[i]
        d-=1
        


ans3 = [["0" for i in range(d)] for j in range(c)]

for i in range(d):
    for j in range(c):
        ans3[j][i] = ans2[i][j]



for i in range(c):
    print(''.join(ans3[i]))