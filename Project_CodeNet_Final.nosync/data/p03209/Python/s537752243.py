# -*- coding: utf-8 -*-
n, x = map(int,input().split())

l = [0 for _ in range(n+1)] #バーガーの長さ
p = [0 for _ in range(n+1)] #パティの枚数
l[0] = 1
p[0] = 1
for i in range(1,n+1):
    l[i] = 3 + 2 * l[i-1]
    p[i] = 1 + 2 * p[i-1]
#print(l)
#print(p)

def solv(n, x): #答えを返します
    #print(n, x)
    if n == 0:
        if x == 1:
            return 1
        if x == 0:
            return 0
    else:
        if x <= 1:
            return 0
        elif 1 < x <= l[n-1] + 1:
            return solv(n-1, x - 1)
        elif x == l[n-1] + 2:
            return solv(n-1, x - 2) + 1
        elif l[n-1] + 3 <= x:
            if x == l[n]:
                return p[n-1] + 1 + solv(n - 1, x - 3 - l[n - 1])
            else:
                return  p[n-1] + 1 + solv(n - 1, x - 2 - l[n - 1])

print(solv(n,x))