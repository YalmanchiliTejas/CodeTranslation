# -*- coding: utf-8 -*-
"""
Created on Sat Jul 20 20:53:54 2019

@author: ctiuser
"""

N = int(input())
A = [int(input()) for i in range(N)]

ans = [A[0]]

for i in range(1,N):
    l,r = 0, len(ans)-1
    p = (r-l)//2 + 1
    if A[i] <= ans[r]:
        ans.append(A[i])
    elif A[i] > ans[l]:
        ans[l] = A[i]
    else:
        tmp = r
        while r - l > 1:
            if A[i] > ans[p]:
                tmp = p
                r = p
                p = (r-l)//2 + l
            else:
                l = p
                p = (r-l)//2 + l
        ans[tmp] = A[i]
#    print(i,ans)
print(len(ans))

