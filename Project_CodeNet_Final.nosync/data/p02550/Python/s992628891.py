# coding: utf-8
N,X,M = map(int,input().split())
INF = 10**10+1
flg = [INF for i in range(M)]
loop = INF
ruiseki = [X]
ans = 0

An = X

for i in range(1,N):
    flg[An] = i
    An = (An**2)%M
    
    ruiseki.append(ruiseki[-1] + An)
    
    if flg[An] != INF:
        k = flg[An]
        loop = i - flg[An] + 1
        loop_v = ruiseki[-1] - ruiseki[k-1]
        break


if N > loop:
    l = (N-k+1)%loop
    if k >=2:
        ans += ruiseki[k-2]
        if l != 0:
            ans += ruiseki[k+l-2] - ruiseki[k-2]
    else:
        if l != 0:
            ans += ruiseki[k+l-2]
    ans += ((N-k+1)//(loop))*loop_v

else :
    ans = ruiseki[-1]

print(ans)