# -*- coding: utf-8 -*-

n, x = map(int, input().split())

a, p = [1], [1]
for i in range(1,n):
    a.append(3 + a[i-1]*2)
    p.append(1 + p[i-1]*2)

def sum(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    elif x <= a[n-1]+1:
        return sum(n-1, x-1)
    else:
        return sum(n-1, x-a[n-1]-2)+1+p[n-1]

print(sum(n, x))
