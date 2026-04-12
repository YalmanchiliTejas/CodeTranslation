#!/usr/bin/env python3
#ABC115 D

n,x = map(int,input().split())

burger = [0]*(n+1)#厚み
p = [0]*(n+1)#パテの数
burger[0],p[0] = 1,1
for i in range(n):
    p[i+1] = 2*p[i]+1
    burger[i+1] = 2*burger[i]+3

def f(n,x):
    if n == 0:
        if x <= 0:
            return 0
        else:
            return 1
    if x == 1:
        if n == 0:
            return 1
        else:
            return 0
    elif x <= burger[n-1] + 1:
        return f(n-1,x-1)
    elif x == burger[n-1] + 2:
        return p[n-1] + 1
    elif burger[n-1] + 2 < x <= 2*burger[n-1] + 2:
        return p[n-1] + 1 + f(n-1,x-2-burger[n-1])
    elif x == 2*burger[n-1] + 3:
        return 2*p[n-1] + 1
ans = f(n,x)
print(ans)
