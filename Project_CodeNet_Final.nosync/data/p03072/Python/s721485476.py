# -*- coding: utf-8 -*-
N = int(input())
b = list(map(int,input().split()))

ans = 0
for i in range(0,N):
    flag = True
    for t in range(0,i):
        #print(t)
        if b[t] > b[i]:
            flag = False
            break
    if flag == True:
        ans += 1

print(ans)