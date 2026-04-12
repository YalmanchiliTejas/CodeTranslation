# -*- coding: utf-8 -*-
def inpl(): return list(map(int, input().split()))
N = int(input())
X = inpl()
Y = [[x, i] for i, x in enumerate(X)]
Y = sorted(Y)
if (N-1)%2==1:
    l = Y[(N-1)//2][0]
    r = Y[(N-1)//2+1][0]
    for i in range(N):
        if X[i]<=l:
            print(r)
        else:
            print(l)